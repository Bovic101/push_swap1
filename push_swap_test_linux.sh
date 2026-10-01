#!/bin/bash

# =============================================================
#                 PUSH_SWAP LINUX TESTER
# =============================================================

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
WHITE='\033[1;37m'
DEF_COLOR='\033[0m'

PUSH_SWAP="./push_swap"
CHECKER="./checker_linux"
TRACES="traces.txt"

# -------------------------------------------------------------
# Check required programs
# -------------------------------------------------------------

if [ ! -x "$PUSH_SWAP" ]; then
	printf "${RED}Error: ./push_swap not found or not executable.${DEF_COLOR}\n"
	exit 1
fi

if [ ! -x "$CHECKER" ]; then
	printf "${RED}Error: ./checker_linux not found or not executable.${DEF_COLOR}\n"
	exit 1
fi

# Start a fresh trace file
: > "$TRACES"

# -------------------------------------------------------------
# Helper functions
# -------------------------------------------------------------

check_sorted()
{
	local ARG="$1"
	local OUTPUT
	local RESULT

	OUTPUT=$(./push_swap $ARG 2>/dev/null)
	RESULT=$(printf "%s\n" "$OUTPUT" | ./checker_linux $ARG 2>/dev/null)

	if [ "$RESULT" = "OK" ]; then
		return 0
	fi

	return 1
}

count_moves()
{
	local ARG="$1"

	./push_swap $ARG 2>/dev/null | wc -l
}

check_memory()
{
	local ARG="$1"
	local LOG

	LOG=$(mktemp)

	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--errors-for-leak-kinds=definite,indirect,possible \
		--error-exitcode=42 \
		./push_swap $ARG \
		> /dev/null 2>"$LOG"

	local STATUS=$?

	if [ "$STATUS" -eq 0 ] \
		&& grep -q "ERROR SUMMARY: 0 errors" "$LOG" \
		&& grep -q "All heap blocks were freed -- no leaks are possible" "$LOG"; then
		rm -f "$LOG"
		return 0
	fi

	cat "$LOG" >> "$TRACES"
	rm -f "$LOG"
	return 1
}

# -------------------------------------------------------------
# Header
# -------------------------------------------------------------

clear

printf "\n"
printf "${MAGENTA}=============================================================${DEF_COLOR}\n"
printf "${MAGENTA}                  PUSH_SWAP LINUX TESTER${DEF_COLOR}\n"
printf "${MAGENTA}=============================================================${DEF_COLOR}\n"
printf "\n"

# =============================================================
# BASIC TESTS
# =============================================================

printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    BASIC TESTS${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

# Empty
OUTPUT=$(./push_swap 2>/dev/null)

if [ -z "$OUTPUT" ]; then
	printf "${GREEN}[OK] Empty${DEF_COLOR}\n"
else
	printf "${RED}[KO] Empty${DEF_COLOR}\n"
	echo "TEST Empty" >> "$TRACES"
fi

# Already sorted
for ARG in \
	"1" \
	"1 2" \
	"1 2 3" \
	"1 2 3 4 5"
do
	if [ "$(count_moves "$ARG")" -eq 0 ]; then
		printf "${GREEN}[OK] Already sorted $ARG${DEF_COLOR}\n"
	else
		printf "${RED}[KO] Already sorted $ARG${DEF_COLOR}\n"
		echo "TEST ALREADY SORTED ARG:$ARG" >> "$TRACES"
	fi
done

# Reverse
for ARG in \
	"2 1" \
	"3 2 1" \
	"4 3 2 1" \
	"5 4 3 2 1" \
	"6 5 4 3 2 1"
do
	if check_sorted "$ARG"; then
		printf "${GREEN}[OK] Reverse $ARG${DEF_COLOR}\n"
	else
		printf "${RED}[KO] Reverse $ARG${DEF_COLOR}\n"
		echo "TEST REVERSE ARG:$ARG" >> "$TRACES"
	fi
done

# =============================================================
# SUBJECT EXAMPLE
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    SUBJECT EXAMPLE${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

ARG="2 1 3 6 5 8"

if check_sorted "$ARG"; then
	printf "${GREEN}[OK] Subject example is sortable${DEF_COLOR}\n"
else
	printf "${RED}[KO] Subject example failed${DEF_COLOR}\n"
	echo "TEST SUBJECT EXAMPLE ARG:$ARG" >> "$TRACES"
fi

printf "\n"
printf "${WHITE}Your output:${DEF_COLOR}\n"

./push_swap $ARG

MOVES=$(count_moves "$ARG")

printf "\n"
printf "${WHITE}Number of moves:${DEF_COLOR}\n"
printf "%s\n" "$MOVES"

# =============================================================
# ERROR TESTS
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    ERROR TESTS${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

check_error()
{
	local NAME="$1"
	shift
	local OUTPUT

	OUTPUT=$(./push_swap "$@" 2>&1)

	if [ "$OUTPUT" = "Error" ]; then
		printf "${GREEN}[OK] Invalid: %s${DEF_COLOR}\n" "$NAME"
	else
		printf "${RED}[KO] Invalid: %s${DEF_COLOR}\n" "$NAME"
		echo "TEST ERROR $NAME OUTPUT:$OUTPUT" >> "$TRACES"
	fi
}

check_error "0 one 2 3" 0 one 2 3
check_error "1 2 2 3" 1 2 2 3
check_error "2147483648" 2147483648
check_error "-2147483649" -2147483649
check_error "1a 2 3" 1a 2 3
check_error "+" +
check_error "--1" --1

# =============================================================
# CHECKER TESTS
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    CHECKER TESTS${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

run_checker_test()
{
	local ARG="$1"
	local MOVES
	local RESULT

	MOVES=$(count_moves "$ARG")
	RESULT=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)

	if [ "$RESULT" = "OK" ]; then
		printf "${GREEN}[OK] %s${DEF_COLOR}\n" "$ARG"
		printf "      Moves: %s\n" "$MOVES"
	else
		printf "${RED}[KO] %s${DEF_COLOR}\n" "$ARG"
		printf "      Moves: %s\n" "$MOVES"
		echo "TEST CHECKER ARG:$ARG RESULT:$RESULT" >> "$TRACES"
	fi
}

run_checker_test "4 67 3 87 23"
run_checker_test "5 4 3 2 1"
run_checker_test "4 3 2 1"
run_checker_test "6 5 4 3 2 1"
run_checker_test "2 1 3 6 5 8"

# =============================================================
# RANDOM 100
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    RANDOM 100${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

ARG100=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')

MOVES100=$(count_moves "$ARG100")
RESULT100=$(./push_swap $ARG100 2>/dev/null | ./checker_linux $ARG100 2>/dev/null)

printf "Moves: %s\n" "$MOVES100"

if [ "$RESULT100" = "OK" ]; then
	printf "${GREEN}[OK] 100 numbers${DEF_COLOR}\n"
else
	printf "${RED}[KO] 100 numbers${DEF_COLOR}\n"
	echo "TEST RANDOM 100 ARG:$ARG100" >> "$TRACES"
fi

# =============================================================
# RANDOM 500
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    RANDOM 500${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

ARG500=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')

MOVES500=$(count_moves "$ARG500")
RESULT500=$(./push_swap $ARG500 2>/dev/null | ./checker_linux $ARG500 2>/dev/null)

printf "Moves: %s\n" "$MOVES500"

if [ "$RESULT500" = "OK" ]; then
	printf "${GREEN}[OK] 500 numbers${DEF_COLOR}\n"
else
	printf "${RED}[KO] 500 numbers${DEF_COLOR}\n"
	echo "TEST RANDOM 500 ARG:$ARG500" >> "$TRACES"
fi

# =============================================================
# MOVE COUNT
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    MOVE COUNT${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

ARG100=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
MOVES100=$(count_moves "$ARG100")

printf "100 numbers: %s moves\n" "$MOVES100"

if [ "$MOVES100" -lt 700 ]; then
	printf "${GREEN}[OK] < 700${DEF_COLOR}\n"
else
	printf "${RED}[KO] >= 700${DEF_COLOR}\n"
fi

ARG500=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
MOVES500=$(count_moves "$ARG500")

printf "500 numbers: %s moves\n" "$MOVES500"

if [ "$MOVES500" -lt 5500 ]; then
	printf "${GREEN}[OK] < 5500${DEF_COLOR}\n"
else
	printf "${RED}[KO] >= 5500${DEF_COLOR}\n"
fi

# =============================================================
# VALGRIND TEST
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    VALGRIND TEST${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

if command -v valgrind >/dev/null 2>&1; then

	printf "Checking push_swap memory...\n"

	if check_memory "5 4 3 2 1"; then
		printf "${GREEN}[MEMORY OK] 5 4 3 2 1${DEF_COLOR}\n"
	else
		printf "${RED}[KO LEAKS / ERRORS] 5 4 3 2 1${DEF_COLOR}\n"
	fi

	printf "Checking push_swap memory with 100 numbers...\n"

	if check_memory "$ARG100"; then
		printf "${GREEN}[MEMORY OK] 100 numbers${DEF_COLOR}\n"
	else
		printf "${RED}[KO LEAKS / ERRORS] 100 numbers${DEF_COLOR}\n"
	fi

	printf "Checking push_swap memory with 500 numbers...\n"

	if check_memory "$ARG500"; then
		printf "${GREEN}[MEMORY OK] 500 numbers${DEF_COLOR}\n"
	else
		printf "${RED}[KO LEAKS / ERRORS] 500 numbers${DEF_COLOR}\n"
	fi

else
	printf "${YELLOW}[WARNING] Valgrind is not installed${DEF_COLOR}\n"
fi

# =============================================================
# LARGE TESTS
# =============================================================

printf "\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "${BLUE}                    LARGE TESTS${DEF_COLOR}\n"
printf "${BLUE}-------------------------------------------------------------${DEF_COLOR}\n"
printf "\n"

for SIZE in 100 200 300 400 500
do
	ARG=$(shuf -i 0-9999 -n "$SIZE" | tr '\n' ' ')
	MOVES=$(count_moves "$ARG")
	RESULT=$(./push_swap $ARG 2>/dev/null | ./checker_linux $ARG 2>/dev/null)

	if [ "$RESULT" = "OK" ]; then
		printf "${GREEN}[OK] Num args: %s  Moves: %s${DEF_COLOR}\n" "$SIZE" "$MOVES"
	else
		printf "${RED}[KO] Num args: %s  Moves: %s${DEF_COLOR}\n" "$SIZE" "$MOVES"
		echo "TEST LARGE SIZE:$SIZE ARG:$ARG" >> "$TRACES"
	fi
done

# =============================================================
# FINAL RESULT
# =============================================================

printf "\n"
printf "${MAGENTA}=============================================================${DEF_COLOR}\n"
printf "${MAGENTA}                    TEST COMPLETE${DEF_COLOR}\n"
printf "${MAGENTA}=============================================================${DEF_COLOR}\n"
printf "\n"

if [ ! -s "$TRACES" ]; then
	printf "${GREEN}All tests passed successfully.${DEF_COLOR}\n"
	rm -f "$TRACES"
else
	printf "${YELLOW}Some tests produced warnings/failures.${DEF_COLOR}\n"
	printf "${CYAN}See: $PWD/$TRACES${DEF_COLOR}\n"
fi

printf "\n"
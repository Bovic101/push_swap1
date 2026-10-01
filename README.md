# Push_swap

> **Algorithm & Data Structures Project**

A C implementation of the **Push_swap** project. The program sorts a sequence of integers using two stacks and only the operations allowed by the Push_swap subject.

## Overview

Push_swap uses:

- **Stack A** — contains the input numbers.
- **Stack B** — auxiliary stack used during sorting.
- A restricted instruction set to manipulate both stacks.

The implementation uses a **cost-based / Turk-style strategy**. For each candidate element, it determines its target position, calculates the required rotations, selects a low-cost move, performs the operation, and repeats until the stack is correctly ordered.

## Requirements

- `gcc`
- `make`
- Linux / Unix shell
- `checker_linux` for verification
- `valgrind` for memory testing

## Compilation Step 1
## Clone the Repository

Clone the project and enter the project directory:

```bash
git clone https://github.com/Bovic101/push_swap1.git
```

```bash
cd push_swap1
```

## Compilation Step 2

From the project directory:

```bash
make
chmod +x manual_sort_test.sh
chmod +x push_swap_test_linux.sh

```

Other Makefile commands:

```bash
make clean
make fclean
make re
```

## Usage

Pass the unsorted integers directly as command-line arguments:

```bash
./push_swap 5 2 8 1 4 3
```

The program prints the Push_swap instructions required to sort the input.

To verify the result:

```bash
ARG="5 2 8 1 4 3"
./push_swap $ARG | ./checker_linux $ARG
```

Expected:

```text
OK
```

## Manual_sort_test

For a simple demonstration with an unsorted input, use:

```bash
./manual_sort_test.sh 8 7 6 5 4 3 2 1
```

The script can be usedd to demonstrate the program with an unsorted random input . You can generate random number by visit https://numbergenerator.org/

You can also demonstrate a manually chosen input directly:

```bash
./push_swap 8 3 6 1 7 2 5 4
```

Then verify it:

```bash
ARG="8 3 6 1 7 2 5 4"
./push_swap $ARG | ./checker_linux $ARG
```

## Push_swap Operations

| Operation | Description |
|:---:|---|
| `sa` | Swap the first two elements of A |
| `sb` | Swap the first two elements of B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of B onto A |
| `pb` | Push the top element of A onto B |
| `ra` | Rotate A upward |
| `rb` | Rotate B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` simultaneously |

## How the Algorithm Works

### 1. Validate the input

The program checks that:

- Arguments are valid integers.
- Values are within the integer range.
- Duplicate values are rejected.

Invalid input prints:

```text
Error
```

Example:

```bash
./push_swap 0 one 2 3
```

### 2. Build Stack A

The input values are stored in a linked-list representation of Stack A. Stack B starts empty.

```text
        TOP
         |
         v
A  ->  [5]
       [2]
       [8]
       [1]
         |
       BOTTOM

B  ->  empty
```

### 3. Handle small stacks

Small inputs are handled separately to avoid unnecessary operations.

Examples:

```bash
./push_swap 2 1
./push_swap 3 2 1
./push_swap 5 4 3 2 1
```

### 4. Move elements between the stacks

Elements are transferred between A and B while maintaining useful relative ordering.

### 5. Assign target positions

When moving an element from **A to B**, the program searches B for the appropriate target:

- the largest value in B that is smaller than the current value;
- if no smaller value exists, the maximum value in B is used.

When moving an element from **B to A**, the program searches A for:

- the smallest value in A that is larger than the current value;
- if no larger value exists, the minimum value in A is used.

### 6. Calculate movement cost

For each candidate, the program calculates how many rotations are required to place both the candidate and its target correctly.

It considers:

- forward rotations;
- reverse rotations;
- simultaneous rotations with `rr`;
- simultaneous reverse rotations with `rrr`.

The candidate with the lowest calculated cost is selected.

### 7. Push and repeat

The selected element is rotated into position and pushed to the other stack.

This process is repeated until the required elements have been transferred.

### 8. Finish Stack A

The remaining elements are moved back to A and Stack A is rotated so that the smallest value is at the top.

The final result is a sorted Stack A.

## Algorithm Flow

```text
              INPUT
                |
                v
        Validate arguments
                |
                v
          Create Stack A
                |
                v
          Already sorted?
             /       \
           YES        NO
            |          |
           STOP        v
                 Handle small stack
                        |
                        v
                Move A <-> B
                        |
                        v
                 Assign targets
                        |
                        v
                Calculate costs
                        |
                        v
              Select cheapest move
                        |
                        v
                 Rotate / push
                        |
                        v
                     Repeat
                        |
                        v
                Move B -> A
                        |
                        v
              Rotate minimum to top
                        |
                        v
                    SORTED
```

## Testing

### 1. Subject example

```bash
./push_swap 2 1 3 6 5 8
```

The generated instructions must correctly sort the input when checked.

### 2. Invalid input

```bash
./push_swap 0 one 2 3
./push_swap 1 2 2 3
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1a 2 3
./push_swap +
./push_swap --1
```

Expected output for invalid input:

```text
Error
```

### 3. Checker test

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Expected:

```text
OK
```

### 4. Random 100 numbers

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
```

### 5. Random 500 numbers

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG
```

The checker should return:

```text
OK
```

## Automated Linux Test

The project includes:

```text
push_swap_test_linux.sh
```

Make it executable if necessary:

```bash
chmod +x push_swap_test_linux.sh
```

Run the complete test suite:

```bash
./push_swap_test_linux.sh
```

The script tests:

- basic sorting cases;
- already sorted inputs;
- reverse-sorted inputs;
- the subject example;
- invalid arguments;
- duplicate values;
- integer overflow;
- checker verification;
- random 100-number inputs;
- random 500-number inputs;
- move counts;
- Valgrind memory checks;
- larger sorting cases.

## Move Count

To count the number of instructions generated:

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

For 500 numbers:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

The exact number varies because the input is random.

## Memory Testing

Use Valgrind to check for leaks and memory errors:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG > /dev/null
```

A clean result should include:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## Project Structure

```text
push_swap/
├── Makefile
├── README.md
├── demo.sh
├── push_swap_test_linux.sh
├── checker_linux
├── push_swap_src/
│   └── push_swap.h
└── source files
```

The source code is organised around:

- input validation;
- stack management;
- Push_swap operations;
- rotations;
- push operations;
- target selection;
- cost calculation;
- sorting logic;
- memory management.

## Project Summary

The key points to explain during a defense are:

1. **Two stacks:** A contains the input and B is used as auxiliary storage.
2. **Target selection:** Every element being moved is assigned an appropriate target in the other stack.
3. **Cost calculation:** The program estimates the rotations needed for a candidate and its target.
4. **Cheapest move:** The candidate with the lowest calculated cost is selected.
5. **Combined rotations:** `rr` and `rrr` reduce the number of instructions when both stacks rotate in the same direction.
6. **Final alignment:** The minimum value is rotated to the top of Stack A.
7. **Validation:** Invalid input and duplicates are rejected.
8. **Memory:** Allocated stack nodes are freed after execution.

## Author

**Odebunmi Victor**

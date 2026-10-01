#!/bin/bash
# Visit  this website to generate a random number for the soting test https://numbergenerator.org/
if [ "$#" -eq 0 ]; then
    echo "Usage: $0 number1 number2 number3 ..."
    exit 1
fi

echo
echo "Unsorted:"
printf "%s " "$@"
echo
echo

echo "Sorting..."
echo

# Run push_swap and save its operations
operations=$(./push_swap "$@")

# Show the operations if desired
# echo "$operations"

# Use checker to verify the result
result=$(echo "$operations" | ./checker_linux "$@")

if [ "$result" = "OK" ]; then
    echo "Sorted:"
    printf "%s\n" "$@" | sort -n | tr '\n' ' '
    echo
    echo
    echo "Result: OK"
else
    echo "Result: KO"
fi
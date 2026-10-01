# Push_swap

> **42 Heilbronn — Push_swap**
>
> A C implementation of the Push_swap sorting project using two stacks, linked-list data structures, the allowed Push_swap operations, and a cost-based Turk sorting strategy.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Objectives](#objectives)
- [Rules and Allowed Operations](#rules-and-allowed-operations)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Visual Stack Model](#visual-stack-model)
- [How the Algorithm Works](#how-the-algorithm-works)
- [The Turk Strategy in This Project](#the-turk-strategy-in-this-project)
- [Special Cases](#special-cases)
- [Input Validation](#input-validation)
- [Testing](#testing)
- [Memory Management](#memory-management)
- [Complexity](#complexity)
- [Defense Guide](#defense-guide)
- [Example Commands](#example-commands)

---

## Project Overview

The goal of **Push_swap** is to sort a list of integers using two stacks:

- **Stack A** — contains the input values at the beginning.
- **Stack B** — starts empty.

The program does not directly sort the values with a normal sorting function. Instead, it generates a sequence of Push_swap instructions that transforms stack A into ascending order.

The project subject specifies that the first argument is the element at the **top of stack A**, and that the final result must have the smallest value at the top.

The available instructions are deliberately limited. The project therefore focuses on data structures, algorithm design, movement cost, and optimization.

---

## Objectives

The implementation focuses on:

- manipulating two stacks efficiently;
- implementing the complete Push_swap instruction set;
- validating integer input;
- detecting duplicates;
- handling `INT_MIN` / `INT_MAX` boundaries;
- choosing useful moves based on calculated movement costs;
- using simultaneous rotations where possible;
- freeing dynamically allocated memory correctly;
- producing only Push_swap instructions on standard output.

The project subject explicitly requires the program to output instructions separated by `\n`, and to print `Error\n` on standard error when an invalid input is detected.

---

## Rules and Allowed Operations

There are two stacks:

```text
        TOP
         │
         ▼
      ┌─────┐
      │  2  │  ← first element
      ├─────┤
      │  7  │
      ├─────┤
      │  4  │
      ├─────┤
      │  9  │
      └─────┘
      STACK A
```

At startup:

```text
STACK A                    STACK B

   TOP                       TOP
    │                         │
    ▼                         ▼
  [ 2 ]                     [   ]
  [ 7 ]                     [   ]
  [ 4 ]                     [   ]
  [ 9 ]                     [   ]
```

The subject defines these operations:

| Instruction | Meaning |
|---|---|
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

These are the operations implemented by the project.

---

## Project Structure

The project is organised around the stack data structure, basic operations, Push_swap operations, and the Turk movement/cost logic.

Important components include:

```text
push_swap1/
│
├── Makefile
├── push_swap_src/
│   └── push_swap.h
│
├── operation.c
├── operation_2.c
├── basic_rot.c
├── basic_rot_2.c
│
├── ... other Push_swap source files ...
│
├── libft/
└── ft_printf/
```

The project header defines the main stack structure:

```c
typedef struct s_push_swap_stack
{
    int                         data;
    int                         count;
    int                         nearval_cal;
    bool                        nearval;
    bool                        push_midval;
    struct s_push_swap_stack   *next;
    struct s_push_swap_stack   *prevnode;
    struct s_push_swap_stack   *desired_node;
}   t_push_swap_stack;
```

### Why a linked list?

The stack is represented as a doubly linked list.

Each node stores:

- `data` — the integer value;
- `count` — its current position;
- `push_midval` — whether the node is in the first/upper half of the stack;
- `desired_node` — its target node in the other stack;
- `nearval_cal` — calculated movement cost;
- `nearval` — identifies the selected node;
- `next` / `prevnode` — links to neighbouring nodes.

This allows the program to move nodes without copying the entire stack.

---

# Installation

## 1. Clone the project

```bash
git clone <your-repository-url>
cd push_swap1
```

## 2. Build the program

```bash
make
```

The project is expected to produce:

```text
./push_swap
```

## 3. Clean object files

```bash
make clean
```

## 4. Remove the executable and object files

```bash
make fclean
```

## 5. Rebuild

```bash
make re
```

---

# Usage

Pass the integers directly as command-line arguments:

```bash
./push_swap 4 67 3 87 23
```

The program prints the operations required to sort the input.

For example:

```text
pb
...
```

The exact sequence depends on the implementation's calculated movement strategy.

### Already sorted input

```bash
./push_swap 1 2 3 4 5
```

Expected:

```text
(no output)
```

### Invalid input

```bash
./push_swap 0 one 2 3
```

Expected:

```text
Error
```

### Duplicate input

```bash
./push_swap 1 2 2 3
```

Expected:

```text
Error
```

---

# Visual Stack Model

## `pb` — Push A → B

Before:

```text
        A                 B

      ┌───┐             ┌───┐
 TOP  │ 2 │             │ 9 │
      ├───┤             ├───┤
      │ 7 │             │ 5 │
      ├───┤             └───┘
      │ 4 │
      └───┘
```

After `pb`:

```text
        A                 B

      ┌───┐             ┌───┐
 TOP  │ 7 │             │ 2 │
      ├───┤             ├───┤
      │ 4 │             │ 9 │
      └───┘             ├───┤
                        │ 5 │
                        └───┘
```

The top element of A becomes the top element of B.

---

## `pa` — Push B → A

`pa` performs the reverse movement:

```text
       B                         A

     [ 2 ]  ───────────────►   [ 2 ]
     [ 9 ]                     [ 7 ]
     [ 5 ]                     [ 4 ]
```

---

## `ra` — Rotate A

Before:

```text
A

[ 2 ]  ← TOP
[ 7 ]
[ 4 ]
[ 9 ]
```

After `ra`:

```text
A

[ 7 ]  ← TOP
[ 4 ]
[ 9 ]
[ 2 ]
```

The first element becomes the last element.

---

## `rra` — Reverse Rotate A

Before:

```text
A

[ 2 ]  ← TOP
[ 7 ]
[ 4 ]
[ 9 ]
```

After `rra`:

```text
A

[ 9 ]  ← TOP
[ 2 ]
[ 7 ]
[ 4 ]
```

The last element becomes the first element.

---

# How the Algorithm Works

The implementation uses a **cost-based Turk strategy**.

At a high level:

```text
                 INPUT
                   │
                   ▼
          Validate arguments
                   │
                   ▼
          Build linked-list A
                   │
                   ▼
             Is A sorted?
              /         \
            YES          NO
             │            │
             ▼            ▼
          Finish       Small-sort /
                       Turk strategy
                            │
                            ▼
                    Push elements
                    between A/B
                            │
                            ▼
                  Calculate positions
                            │
                            ▼
                   Find target nodes
                            │
                            ▼
                   Calculate costs
                            │
                            ▼
                    Select cheapest
                            │
                            ▼
                 Rotate efficiently
                            │
                            ▼
                       Push node
                            │
                            ▼
                 Recalculate positions
                            │
                            ▼
                  Move B → A correctly
                            │
                            ▼
                  Final rotation of A
                            │
                            ▼
                         SORTED
```

---

# The Turk Strategy in This Project

The important idea is that the algorithm does not simply choose the next numerical value and rotate it blindly.

Instead, it asks:

> **Which element can I move to its correct relative position with the lowest movement cost?**

The implementation contains functions specifically for this strategy:

```c
index_position()
assign_t4a()
assign_t4b()
push_cost4a()
chose_closest_val()
turk_implement()
turk_implement_b()
```

These functions work together.

---

## Step 1 — Index the nodes

`index_position()` walks through a stack and assigns every node a position:

```text
Position:

0 → top
1
2
3
4 → bottom
```

It also determines whether the node is in the first/upper half of the stack.

Conceptually:

```text
        TOP

        [ A ]  position 0
        [ B ]  position 1
        [ C ]  position 2
        [ D ]  position 3
        [ E ]  position 4

        BOTTOM
```

The `push_midval` flag records which side of the midpoint the node belongs to.

This helps decide whether a node should be reached with:

```text
rotate
```

or:

```text
reverse rotate
```

---

# Step 2 — Find a target node

When moving a node from A to B, the algorithm determines where that node should go in B.

The function:

```c
assign_t4a(a, b);
```

searches B for the appropriate target.

For a value in A, it searches for the closest smaller value in B. If such a value does not exist, it uses the maximum value in B as the target.

Conceptually:

```text
A                         B

[ 42 ]                    [ 50 ]
[ ... ]                   [ 30 ]
                          [ 20 ]
                          [ 10 ]

42's target in B → 30
```

If there is no value smaller than `42`, the target becomes the maximum value in B.

---

# Step 3 — Calculate movement cost

Once a target has been identified, the algorithm calculates how many operations are required to place the node and its target at the top.

This is handled by:

```c
push_cost4a()
```

The algorithm calculates:

```text
cost to move node in A
+
cost to move target in B
```

When both nodes require movement in the same direction, simultaneous rotations can reduce the total cost.

For example:

```text
A needs: ra ra ra
B needs: rb rb

Instead of:

ra
ra
ra
rb
rb

the algorithm can use:

rr
rr
ra
```

This is cheaper in terms of Push_swap instructions.

Similarly, reverse rotations can be combined using:

```text
rrr
```

---

# Step 4 — Select the cheapest candidate

`chose_closest_val()` scans the calculated costs and marks the node with the lowest cost.

Conceptually:

```text
Candidate      Cost

Node A           8
Node B           4   ← selected
Node C           7
Node D           5
```

The selected node is marked using:

```c
nearval = true;
```

This is the node the algorithm attempts to move next.

---

# Step 5 — Perform simultaneous rotations

If the selected node and its target are both in the upper half:

```text
ra + rb
```

can become:

```text
rr
```

If both are in the lower half:

```text
rra + rrb
```

can become:

```text
rrr
```

The project implements this logic through:

```c
rot_ab()
rrot_both()
```

This is one of the important optimization ideas in the implementation.

---

# Step 6 — Move the selected node

After positioning the selected node and its target, the algorithm performs the push operation.

The project uses:

```c
pb()
```

when moving:

```text
A → B
```

and:

```c
pa()
```

when moving:

```text
B → A
```

The lower-level linked-list movement is handled by:

```c
activate_push()
```

---

# Step 7 — Recalculate positions

After a rotation or push, node positions change.

Therefore the algorithm recalculates the stack metadata before making subsequent decisions.

This is important because a node that was previously near the top may no longer be near the top after a rotation.

---

# Step 8 — Move elements back from B to A

After the first phase, the algorithm uses:

```c
assign_t4b()
```

to determine the correct target in A for nodes in B.

For a value in B, the function looks for the smallest value in A that is greater than the B value.

If there is no greater value, it uses the minimum value in A.

Conceptually:

```text
A                         B

[ 10 ]                    [ 7 ]
[ 20 ]                    [ ... ]
[ 30 ]

Target for 7 → 10
```

The node is then moved to A using:

```c
pa()
```

---

# Step 9 — Final rotation

After all values have returned to A, A may be sorted circularly but its smallest value may not yet be at the top.

The final step is therefore to rotate A until the minimum value is at the top.

Conceptually:

```text
Before:

[ 4 ] ← TOP
[ 5 ]
[ 1 ]
[ 2 ]
[ 3 ]

             rotate

After:

[ 1 ] ← TOP
[ 2 ]
[ 3 ]
[ 4 ]
[ 5 ]
```

The result is ascending order.

---

# Small Input Strategy

The implementation also provides an alternative sorting path:

```c
alt_sorter()
```

This is used for smaller stacks instead of applying the full Turk strategy unnecessarily.

For example, very small inputs can be solved directly using combinations of:

```text
sa
ra
rra
```

This reduces unnecessary algorithmic overhead.

---

# Input Validation

The program validates the command-line input before sorting.

Examples of invalid input include:

### Non-numeric values

```bash
./push_swap 1 two 3
```

### Duplicate values

```bash
./push_swap 1 2 2 3
```

### Values outside the `int` range

```bash
./push_swap 2147483648
```

```bash
./push_swap -2147483649
```

### Invalid signs

```bash
./push_swap +
```

```bash
./push_swap --1
```

For invalid input, the program prints:

```text
Error
```

to standard error.

---

# Testing

## Basic tests

```bash
./push_swap 1 2 3 4 5
```

Already sorted input should produce no instructions.

Reverse order:

```bash
./push_swap 5 4 3 2 1
```

Check the result with a checker:

```bash
./push_swap 5 4 3 2 1 | ./checker_linux 5 4 3 2 1
```

Expected:

```text
OK
```

---

## Subject example

```bash
./push_swap 2 1 3 6 5 8
```

The project subject uses this input to demonstrate the required Push_swap instruction format.

Your implementation may produce a different valid sequence from the example sequence because the subject requires a minimal/low operation count rather than one unique sequence.

To verify correctness:

```bash
./push_swap 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
```

Expected:

```text
OK
```

---

# Random Testing

Generate 100 random unique numbers:

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
```

Run the program:

```bash
./push_swap $ARG
```

Count the generated instructions:

```bash
./push_swap $ARG | wc -l
```

Check the result:

```bash
./push_swap $ARG | ./checker_linux $ARG
```

Expected:

```text
OK
```

For 500 numbers:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')

./push_swap $ARG | wc -l

./push_swap $ARG | ./checker_linux $ARG
```

---

# Memory Testing

Use Valgrind:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 5 4 3 2 1
```

A clean run should end with information equivalent to:

```text
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors
```

The project also includes automated testing through:

```bash
./push_swap_test_linux.sh
```

---

# Complexity

The project subject emphasizes algorithmic efficiency and compares the number of generated operations against evaluation limits.

This implementation uses a cost-based strategy rather than repeatedly performing a simple selection sort.

The expensive part of the strategy is repeatedly:

1. indexing nodes;
2. searching for target nodes;
3. calculating movement costs;
4. selecting the lowest-cost candidate.

Because these operations involve traversing linked lists, individual decisions can require linear scans of the stacks. The overall practical complexity depends on the exact input and movement decisions.

For the defense, the important point is:

> The implementation is designed to reduce the **number of Push_swap instructions**, especially by choosing a low-cost candidate and combining rotations with `rr` / `rrr`.

Do not claim a precise asymptotic complexity for the entire implementation unless you have formally analysed every sorting path.

---

# Defense Guide

## 30-second explanation

> “My Push_swap uses two linked-list stacks, A and B. I first validate the input and create stack A. For small inputs I use a dedicated small-stack sorter. For larger inputs I use a Turk-style cost-based strategy. Each node gets a position, a target node in the other stack, and a movement cost. I select the node with the lowest cost and rotate the two stacks toward their target, combining rotations with `rr` or `rrr` when possible. I then push the node, recalculate the positions, and continue. Finally, I move the elements back into A and rotate A so that the minimum value is at the top.”

---

## If the evaluator asks: “Why two stacks?”

> “The Push_swap subject restricts the algorithm to two stacks and a limited set of operations. Stack B acts as temporary storage while I position values relative to their targets.”

---

## If asked: “What is your algorithm?”

> “It is a cost-based Turk strategy. I assign each node a position, find its target in the other stack, calculate the movement cost, select the cheapest candidate, perform the necessary rotations, and push it.”

---

## If asked: “What is `desired_node`?”

> “It is the target node that a selected node should be positioned next to in the other stack. The target is selected according to the relative value ordering.”

---

## If asked: “What is `nearval_cal`?”

> “It stores the calculated movement cost for a candidate node. I use it to select the candidate that can be moved with the lowest calculated cost.”

---

## If asked: “Why `rr` instead of `ra` and `rb`?”

> “If both stacks need to rotate in the same direction, `rr` performs both rotations in one Push_swap instruction. This reduces the total number of operations.”

---

## If asked: “Why `rrr`?”

> “The same optimization applies when both stacks need reverse rotation. `rrr` combines `rra` and `rrb`.”

---

## If asked: “Why do you recalculate positions?”

> “Because rotations and pushes change the position of every affected node. The movement cost must be based on the current state of the stacks.”

---

## If asked: “How do you handle errors?”

> “I validate that every argument represents a valid integer, check the integer range, and reject duplicate values. On invalid input I print `Error` to standard error.”

---

## If asked: “How do you prove that it works?”

Use the checker:

```bash
./push_swap $ARG | ./checker_linux $ARG
```

If it prints:

```text
OK
```

the generated instruction sequence correctly sorts the supplied input.

Then demonstrate memory safety with:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG
```

---

# Quick Defense Demo

A simple sequence to demonstrate during evaluation:

### 1. Build

```bash
make
```

### 2. Show a simple input

```bash
./push_swap 5 4 3 2 1
```

### 3. Verify it

```bash
./push_swap 5 4 3 2 1 | ./checker_linux 5 4 3 2 1
```

Expected:

```text
OK
```

### 4. Show invalid input

```bash
./push_swap 0 one 2 3
```

Expected:

```text
Error
```

### 5. Generate random input

```bash
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
```

### 6. Show the input

```bash
echo "$ARG"
```

### 7. Sort it

```bash
./push_swap $ARG
```

### 8. Verify it

```bash
./push_swap $ARG | ./checker_linux $ARG
```

Expected:

```text
OK
```

### 9. Count operations

```bash
./push_swap $ARG | wc -l
```

### 10. Check memory

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG > /dev/null
```

---

# Useful Commands

```bash
# Build
make

# Clean
make clean

# Full clean
make fclean

# Rebuild
make re

# Run
./push_swap 4 67 3 87 23

# Check
./push_swap 4 67 3 87 23 | ./checker_linux 4 67 3 87 23

# Count operations
./push_swap 4 67 3 87 23 | wc -l

# Generate random input
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')

# Display random input
echo "$ARG"

# Sort random input
./push_swap $ARG

# Verify random input
./push_swap $ARG | ./checker_linux $ARG

# Valgrind
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $ARG
```

---

# Project Requirements

The Push_swap subject requires:

- a C implementation;
- a `Makefile`;
- no global variables;
- stack A containing the input;
- stack B initially empty;
- valid Push_swap operations only;
- ascending order in A at the end;
- no output for empty input;
- `Error\n` for invalid input;
- proper memory management;
- operation output separated by newlines.

The official subject also emphasizes algorithmic efficiency: the generated instruction count is compared against evaluation limits.

---

## Final Defense Summary

Remember these five points:

```text
1. INPUT
   Validate → build linked-list A

2. POSITION
   Index nodes and determine rotation direction

3. TARGET
   Find the appropriate target node in the other stack

4. COST
   Calculate movement cost → select cheapest candidate

5. EXECUTE
   Rotate → push → recalculate → repeat → final rotation
```

### The key sentence to remember

> **“I don't just move the next number; I calculate where each candidate should go, how much it will cost to move it there, and choose the candidate with the lowest calculated movement cost.”**

---

## Reference

The implementation follows the rules and operation model defined by the 42 Push_swap subject. The project source defines the linked-list stack structure and the Turk-related functions used by the implementation.


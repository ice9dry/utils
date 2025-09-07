#!/bin/bash

# Define the path to your program
PROGRAM="/home/marlee/projects/push_swap/push_swap"
CHECKER="/home/marlee/projects/push_swap/checker_linux"

args=(
""
"0" #single number
"1" #single number
"-2147483648" #INT_MIN
"2147483647" #INT_MAX
"-2147483649" #INT_MIN -1
"1 2"
"1 2 3"
"1 2 3 4"
"1 2 3 4 5"
"5 1 2 3 4"
"5 1 2 3 4"
"-100 2 4 344 343 1 455 986"
"one 1 3"
"'2 43 -1'"
"2147483647 -2147483648"
"-2147483647 -2147483648"
"-2147483648 -2147483647"
"-2147483648 -2147483648"
"2147483647 2147483647"
"2147483647 2147483646"
"2147483646 2147483647"
)

for ARG in "${args[@]}"; do
	echo "~~~ arg is: ${ARG} ~~~"
	eval "$PROGRAM $ARG | $CHECKER $ARG"
	eval "$PROGRAM $ARG | wc -l"
done

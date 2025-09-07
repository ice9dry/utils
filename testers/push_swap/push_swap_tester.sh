#!/bin/bash

# Define the path to your program
PROGRAM="/home/marlee/projects/push_swap/push_swap"
CHECKER="/home/marlee/projects/push_swap/checker_linux"

args=(
#NOT OK
"1 '2 three' 4" 
"-2147483649" #INT_MIN -1
"one 1 3"
"'one'"
"2 'one' 3"
"-2147483648 -2147483648"
"2147483647 2147483647"
#OK
""
"0" #single number
"1" #single number
"-2147483648" #INT_MIN
"2147483647" #INT_MAX
"1 2"
"1 2 3"
"1 2 3 4"
"1 2 3 4 5"
"5 1 2 3 4"
"5 1 2 3 4"
"'2 43 -1'"
"-100 2 4 344 343 1 455 986"
"-2147483648 -2147483647"
"2147483647 -2147483648"
"-2147483647 -2147483648"
"2147483647 2147483646"
"2147483646 2147483647"
"1 '2' 3"
"1 '2 3' 4"
"1 '3 2' 4"
"-12342334 '-2147483648'"
"-12342334 '-2147483648 0' 60"
"-12342334 '-2147483648 0 4 3' 60 2"
)

for ARG in "${args[@]}"; do
	echo "~~~ arg is: ${ARG} ~~~"
	eval "$PROGRAM $ARG | $CHECKER $ARG"
	eval "$PROGRAM $ARG | wc -l"
done

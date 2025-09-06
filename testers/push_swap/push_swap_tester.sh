#!/bin/bash

# Define the path to your program
PROGRAM="/home/marlee/projects/push_swap/bin/main.out"
ls
# Test cases
echo "--- Running Test Case 1: All integers ---"
echo $PROGRAM 1 2 3 4 4

echo "--- Running Test Case 2: Different integers ---"
$PROGRAM 1 4 5 5

echo "--- Running Test Case 3: Mixed string and integers ---"
$PROGRAM one 1 3

echo "--- Running Test Case 4: Quoted string argument ---"
$PROGRAM "2 43 -1"

# You can add more test cases as needed
echo "--- Running Test Case 5: No arguments ---"
$PROGRAM

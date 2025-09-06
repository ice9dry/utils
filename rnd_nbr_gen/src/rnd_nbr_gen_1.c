#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define NUMBERS_TO_GENERATE 20

// Function to check for duplicates in the array
int is_duplicate(int *arr, int size, int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int numbers[NUMBERS_TO_GENERATE];
    int count = 0;
    long long rand_num;
    
    srand(time(NULL));

    // Generate unique random numbers
    while (count < NUMBERS_TO_GENERATE) {
        // Generate a random number within the INT range
        rand_num = ((long long)rand() * ((long long)INT_MAX - INT_MIN)) / RAND_MAX + INT_MIN;
        
        if (!is_duplicate(numbers, count, rand_num)) {
            numbers[count] = rand_num;
            count++;
        }
    }

    // Print the numbers with spaces in between
    int i;
    for (i = 0; i < NUMBERS_TO_GENERATE; i++) {
        printf("%d", numbers[i]);
        if (i < NUMBERS_TO_GENERATE - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define NUMBERS_TO_GENERATE 100
#define MIN_RANGE 0
#define MAX_RANGE 23000

// Function to check for duplicates in the array
int is_duplicate(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int numbers[NUMBERS_TO_GENERATE];
    int count = 0;
    int rand_num;

    srand(time(NULL));

    // Generate unique random numbers
    while (count < NUMBERS_TO_GENERATE) {
        // Generate a random number within the INT range
        // This is a common and more reliable way to generate a full-range int
        // rand_num = (int)(((long long)rand() << 16) | rand());
		rand_num = (rand() % (MAX_RANGE - MIN_RANGE + 1)) + MIN_RANGE;

        if (!is_duplicate(numbers, count, rand_num)) {
            numbers[count] = rand_num;
            count++;
        }
    }

    // Print the numbers with spaces in between
    for (int i = 0; i < NUMBERS_TO_GENERATE; i++) {
        printf("%d", numbers[i]);
        if (i < NUMBERS_TO_GENERATE - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
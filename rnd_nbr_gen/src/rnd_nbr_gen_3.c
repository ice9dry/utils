#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> // Not strictly needed for this modified version, but kept for completeness

// Function to check for duplicates in the array
int is_duplicate(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int num_to_generate;
    int min_range;
    int max_range;

    // Check if the correct number of arguments is provided
    if (argc != 4) {
        printf("Usage: %s <number_of_elements> <min_range> <max_range>\n", argv[0]);
        return 1; // Indicate an error
    }

    // Convert command-line arguments to integers
    num_to_generate = atoi(argv[1]);
    min_range = atoi(argv[2]);
    max_range = atoi(argv[3]);

    // Basic validation for the arguments
    if (num_to_generate <= 0 || min_range > max_range || num_to_generate > (max_range - min_range + 1)) {
        printf("Invalid arguments. Please ensure:\n");
        printf("  - Number of elements is positive.\n");
        printf("  - Min range is less than or equal to max range.\n");
        printf("  - Number of elements does not exceed the possible unique numbers in the range.\n");
        return 1;
    }

    // Dynamically allocate memory for the numbers array
    // This is necessary as NUMBERS_TO_GENERATE is no longer a fixed #define
    int *numbers = (int *)malloc(num_to_generate * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int count = 0;
    int rand_num;

    srand(time(NULL));

    // Generate unique random numbers
    while (count < num_to_generate) {
        rand_num = (rand() % (max_range - min_range + 1)) + min_range;

        if (!is_duplicate(numbers, count, rand_num)) {
            numbers[count] = rand_num;
            count++;
        }
    }

    // Print the numbers with spaces in between
    for (int i = 0; i < num_to_generate; i++) {
        printf("%d", numbers[i]);
        if (i < num_to_generate - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(numbers);

    return 0;
}
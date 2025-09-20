#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

/* Exit hook: runs when the program finishes */
static void exit_handler(void) {
    printf("Program exiting. errno = %d\n", errno);
}

int print_array(int *arr, int size) {
    assert(arr != NULL);
    assert(size > 0);

    if (arr == NULL || size <= 0) {
        errno = EINVAL;  /* invalid argument */
        fprintf(stderr, "Error: invalid array or size.\n");
        return -1;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

int vectorized_divide(int *a, int *b, int *result, int size) {
    assert(a != NULL && b != NULL && result != NULL);
    assert(size > 0);

    if (a == NULL || b == NULL || result == NULL || size <= 0) {
        errno = EINVAL;
        fprintf(stderr, "Error: invalid input to vectorized_divide.\n");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (b[i] == 0) {
            errno = EDOM;  /* division by zero */
            fprintf(stderr, "Error: division by zero at index %d\n", i);
            return -2;
        }
        /* Note: we’re not adding extra headers, so we’re not checking for the
           rare int overflow case (INT_MIN / -1). */
        result[i] = a[i] / b[i];
    }
    return 0;
}

int main(void) {
    atexit(exit_handler);
    errno = 0;  /* ensure clean state for success path */

    int numbers[5]  = {1, 2, 3, 4, 20};
    int divisors[5] = {0, 1, 2, 3, 4};
    int results[5]  = {0};

    if (vectorized_divide(numbers, divisors, results, 5) != 0) {
        perror("vectorized_divide failed");
        return EXIT_FAILURE;
    }

    if (print_array(results, (int)(sizeof(results) / sizeof(results[0]))) != 0) {
        perror("print_array failed");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

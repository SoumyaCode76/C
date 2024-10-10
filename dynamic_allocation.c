#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc
    int *arr1 = (int *)malloc(5 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initializing and printing arr1
    for (int i = 0; i < 5; i++) {
        // arr1[i] = i + 1;
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }

    // Using calloc
    int *arr2 = (int *)calloc(5, sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed\n");
        free(arr1);
        return 1;
    }

    // Printing arr2 (initialized to zero)
    for (int i = 0; i < 5; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Using realloc
    arr1 = (int *)realloc(arr1, 10 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory reallocation failed\n");
        free(arr2);
        return 1;
    }

    // Initializing and printing the new elements of arr1
    for (int i = 5; i < 10; i++) {
        arr1[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        printf("arr1[%d] = %d\n", i, arr1[i]);
    }

    // Freeing allocated memory
    free(arr1);
    free(arr2);

    return 0;
}
#include <stdio.h>

int X[] = { 12, -5, 7, -20, 3, -1, 18, -9, 0, 4 };

void merge_sort_array(int * X, unsigned int low, unsigned int high);

int main(void)
{
    unsigned int len_arr = sizeof(X)/sizeof(X[0]);
    printf("Original array: ");
    for(int i = 0; i < len_arr; i++)
    {
        printf("%d, ", X[i]);
    }
    merge_sort_array(X, 0, len_arr-1);
    printf("\nSorted array: ");
    for(int i = 0; i < len_arr; i++)
    {
        printf("%d, ", X[i]);
    }
    printf("\n");    
    return 0;

}

void merge_sort_array(int * X, unsigned int low, unsigned int high)
{
    return;
}
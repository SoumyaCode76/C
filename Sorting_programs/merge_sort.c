#include <stdio.h>

int X[] = { 12, -5, 7, -20, 3, -1, 18, -9, 0, 4 };

void merge_sort_array(int * X, unsigned int low, unsigned int high);
void sort_part_arrays(int * X, unsigned low, unsigned high);

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
    if(low >= high)
    {
        return;
    }
    else
    {
        unsigned int mid = (unsigned int)((low + high) / 2);
        merge_sort_array(X, low, mid);
        merge_sort_array(X, mid + 1, high);
        /* When both the arrays are out, sort using selection sort algorithm */
        sort_part_arrays(X, low, high);
    }
}

void sort_part_arrays(int * X, unsigned low, unsigned high)
{
    for(int i = low; i <= high; i++)
    {
        for(int j = low; j < high - i; j++)
        {
            if(X[j] > X[j + 1])
            {
                X[j] = X[j] ^ X[j + 1];
                X[j + 1] = X[j] ^ X[j + 1];
                X[j] = X[j] ^ X[j + 1];
            }
        }
    }
}
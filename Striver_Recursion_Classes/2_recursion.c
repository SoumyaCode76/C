/* 
    * C program to understand how the factorial of a number is calculated using recursion.
    120 = 5 * 4 * 3 * 2 * 1 = 1 * 2 * 3 * 4 * 5
    i = 1, i <= 5, prod = 1 * 1, static prod = 1
    i = 2, i <= 5, prod = 1 * 2
    i = 3, i <= 5, prod = 2 * 3
    i = 4, i <= 5, prod = 6 * 4
    i = 5, i <= 5, prod = 24 * 5
    i = 6, return prod
    stacking part:
    prod = prod * i
    unstacking part:
    } } } } ... } (no new operation)
*/


#include <stdio.h>

int factorial(int n)
{
    static int i = 1; 
    static int prod = 1;

    if(i > n)
    {
        return prod;
    }
    else
    {
        prod = prod * i;
        i++;
        factorial(n);
    }
}

int main(void)
{
    int fact = factorial(5);
    printf("Factorial: %d\n", fact);
    return 0;
}
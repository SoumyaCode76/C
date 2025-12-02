/* Print linearly from 1 to N */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define IMPLEMENTATION_1                                        (1)
#define IMPLEMENTATION_2                                        (0)

void print_numbers(uint32_t i, uint32_t N);


int main(uint32_t argc, int8_t * argv[])
{
    uint32_t N = 0;
    if(argc > 1)
    {
        N = abs(atoi(argv[1]));
#if IMPLEMENTATION_1
        uint32_t idx = 1;
#elif IMPLEMENTATION_2
        uint32_t idx = N;
#endif
        print_numbers(idx, N);
    }
    else
    {
        printf("Usage: Enter the limit to print the numbers upto, as the argument.\n");
        errno = EINVAL;
        perror("Invalid number of arguments");
        return -1;
    }
}

void print_numbers(uint32_t i, uint32_t N)
{
#if IMPLEMENTATION_1
    if(i > N)
    {
        return;
    }
    else
    {
        printf("%d\n", i);
        print_numbers(i + 1, N);
        return;
    }
#elif IMPLEMENTATION_2
    if(i == 0)
    {
        return;
    }
    else{
        print_numbers(i - 1, N);
        printf("%d\n", i);
    }
#endif
}
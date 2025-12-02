/* Print N to 1 linearly using forward-tracking and back-tracking recursive calls */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define FORWARD_TRACKING                                        (1)
#define BACK_TRACKING                                           (0)

void print_numbers(uint32_t i, uint32_t N);


int main(uint32_t argc, int8_t * argv[])
{
    uint32_t N = 0;
    if(argc > 1)
    {
        N = abs(atoi(argv[1]));
#if FORWARD_TRACKING
        uint32_t idx = N;
#elif BACK_TRACKING
        uint32_t idx = 1;
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


#if FORWARD_TRACKING
    void print_numbers(uint32_t i, uint32_t N)
    {
        if(i == 0)
        {
            return;
        }
        else
        {
            printf("%d\n", i);
            print_numbers(i - 1, N);
            return;
        }
    }
#elif BACK_TRACKING
    void print_numbers(uint32_t i, uint32_t N)
    {
        if(i > N)
        {
            return;
        }
        else
        {
            print_numbers(i + 1, N);
            printf("%d\n", i);
        }
    }
#endif

    
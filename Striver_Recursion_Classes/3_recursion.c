/* Write a C program to print a given name N number of times using recursive calls */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

void print_name(uint32_t i, uint32_t N, uint8_t * name);


int main(uint32_t argc, int8_t * argv[])
{
    uint32_t N = 0;
    uint8_t * name = NULL;
    if(argc > 2)
    {
        N = abs(atoi(argv[1]));
        name = argv[2];
        uint32_t idx = 1;
        print_name(idx, N, name);
    }
    else
    {
        printf("Usage: Enter the number of times to print the name as the first argument.\n Enter the name to print as the second argument\n");
        perror("Invalid number of arguments");
        return -1;
    }
}

void print_name(uint32_t i, uint32_t N, uint8_t * name)
{
    if(i > N)
    {
        return;
    }
    else
    {
        printf("Count: %d; %s\n", i, name);
        print_name(i+1, N, name);
        return;
    }
}
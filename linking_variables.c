#include <stdio.h>

int global_var = 10; // .data section
static volatile int static_var; // .bss section

int main() {
    printf("Hello, World!\n");
    return 0;
}
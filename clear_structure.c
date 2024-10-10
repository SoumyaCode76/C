#include <stdio.h>
#include <stdint.h>

struct S1{
    int a;
    int b;
    int c;
};

void clear_structure(void * p, int size){
    uint8_t *ptr = (uint8_t *)p;
    for(int i = 0; i < size; i++){
        ptr[i] = 0;
    }
}

int main(){
    struct S1 s1;
    s1.a = 1;
    s1.b = 2;
    s1.c = 3;
    struct S1 *p = &s1;
    clear_structure(&s1, sizeof(s1));
    printf("s1.a = %d\n", p->a);
    return 0;
}
#include <stdio.h>

int counter = 0;

void func(void){
    /* Stopping condition */
    if(counter == 5)
    {
        printf("%d\n", counter);
        return;
    }
    else
    {
        /* When stacking up */
        printf("%d\n", counter);
        counter++;
        func();
        /* When unstacking */
        printf("%d\n", counter);
        counter--;
    }
}

int main(void){
    func();
    return 0;
}
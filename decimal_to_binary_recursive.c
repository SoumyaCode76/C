#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct tag_binary{
    unsigned char bin[32];
    char idx;
}tBinary;

/* 5 = 1 0 1; 5 2 1

decimal_to_binary(5, Bin){
    append 1
    idx++
    decimal_to_binary(2, Bin){
        append 0
        idx++
        decimal_to_binary(1, Bin){
            append 1
            idx++
            decimal_to_binary(0, Bin){
                idx--
            }
            print 1
            idx--
        }
        print 0
        idx--
    }
    print 1
    idx--
} */


void decimal_to_binary(unsigned int n, tBinary * Bin){
    if(n == 0){
        printf("Binary equivalent: ");
        Bin->idx--;
    }
    else{
        Bin->bin[Bin->idx] = 0x30 + (n % 2);
        Bin->idx++;
        decimal_to_binary(n / 2, Bin);
        printf("%c", Bin->bin[Bin->idx--]);
        if(Bin->idx == -1){
            Bin->idx = 0;
            printf("\n");
        }
    }
}

int main(int argc, char * argv[]){
    tBinary bin_no;
    memset((void *)&bin_no, (unsigned int)'\0', sizeof(tBinary));
    unsigned int N = 0;
    if(argc > 1){
        int n = atoi(argv[1]);
        N = (n < 0) ? (0xFFFFFFFF + 1 + n) : n;
        printf("Decimal number to convert: %d\n", N);
    }
    decimal_to_binary(N, &bin_no);
    return 0;
}


typedef struct tag_binary{
    unsigned char bin[32];
    unsigned char idx;
}tBinary;

tBinary bin_no;

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
        print Bin->bin[Bin->idx];
        Bin->idx--;
    }
    else{
        Bin->bin[Bin->idx++] = n % 2;
        decimal_to_binary(n / 2, Bin)
    }
}

int main(void){

}


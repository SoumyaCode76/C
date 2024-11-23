#include <stdio.h>

/* get size of file in bytes and */

int main(void){
    /*
    * 1. first byte is the flag byte
    * 2. traverse through the flag byte and check if the bit is set and reset
    * 3. if the bit is set, then the next 2 bytes are the offset and length
    * 4. if the bit is reset, then the next byte is the character
    * 5. while traversing, increment the index of the input array
    * 6. keep appending the characters to the output array
    */

}
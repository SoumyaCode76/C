#include <stdio.h>
#include <stdint.h>

/* 
    * Approaching the problem following the dynamic programming approach
    * The problem is to convert a given decimal number to binary number
    * Assumption: 32-bit signed number
    * The problem can be split up into 4 sub-problems.
    * Problem 1: Take input from user. 
    * Problem 2: Check whether it's positive or negative. If negative, convert it to its 2-s complement form
    * Problem 3: Define an character array of 32 bits. Convert the decimal number and save it to the character array
    * Problem 4: Reverse the array to represent the binary number in Little-endian format
    * Auxiliary problem: Print the binary number
 */

/* Subproblem 1 solution */
void take_input_from_user(int32_t * num){
    printf("Enter a number: \n");
    scanf("%d", num);
}

/* Subproblem 2 solution */
uint32_t adjust_negative_input(int32_t * num){
    return (uint32_t)(*num);
}

/* Subproblem 3 solution */
void convert_decimal_to_binary(int32_t num, uint8_t * binarray){
    uint8_t idx = 0;
    uint32_t absolute_num = adjust_negative_input(&num);
    while (absolute_num != 0)
    {
        binarray[idx++] = absolute_num % 2;
        absolute_num /= 2;
    }
    
}

/* Subproblem 4 solution */
void represent_binary_array_in_little_endian(uint8_t * binarray, uint8_t length){
    uint8_t tmp;    
    for(uint8_t idx = 0; idx < length/2 ; idx++){
        tmp = binarray[idx];
        binarray[idx] = binarray[length - idx - 1];
        binarray[length - idx - 1] = tmp;
    }
}

/* Auxiliary subproblem: Print the binary number */
void print_binary_number(uint8_t * binarray, uint8_t length){
    printf("0x");
    for(uint8_t idx = 0; idx < length; idx++){
        printf("%c", binarray[idx] + 0x30);
    }
    printf("\n");
}


int main(void){

    int32_t number = 0;
    uint8_t binary_digits[sizeof(int32_t) * 8] = {0};
    take_input_from_user(&number);
    adjust_negative_input(&number);
    convert_decimal_to_binary(number, binary_digits);
    represent_binary_array_in_little_endian(binary_digits, sizeof(binary_digits));
    print_binary_number(binary_digits, sizeof(binary_digits));

    return 0;

}
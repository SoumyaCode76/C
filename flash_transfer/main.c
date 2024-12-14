#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The main function will do the following: 
    * Define a buffer to store the data to be transferred of variable size
    * 25 bytes original, take out 10 at a time, send 4 bytes at a time to the screen
*/

void fill_data_array(char *data_array, unsigned int data_length){
    for(int i = 0; i < data_length; i++){
        data_array[i] = i;
    }
}

void fill_input_array(const char *data_array, char *input_array, unsigned int input_length){
    for(int i = 0; i < input_length; i++){
        input_array[i] = data_array[i];
    }
}

void transfer_data(const char *input_data, 
                    unsigned int * number_of_bytes_left_to_transfer,
                    char *output_data,
                    unsigned int * number_of_places_left
                    )
{
        unsigned int inpos = *number_of_bytes_left_to_transfer;
        unsigned int outpos = *number_of_places_left;
        while(outpos > 0 && inpos > 0){
            output_data[outpos] = input_data[inpos];
            inpos--;
            outpos--;
        }
        *number_of_bytes_left_to_transfer = inpos;
        *number_of_places_left = outpos;
}

int main(){
    int original_data_length = 0;
    printf("Enter the length of the data to be transferred: \n");
    scanf("%d", &original_data_length);    
    char original_data[original_data_length];
    fill_data_array(original_data, original_data_length);
    unsigned int input_data_length = 0;
    printf("Enter the length of each input block data: \n");
    scanf("%d", &input_data_length);
    char input_data[input_data_length];
    unsigned int input_data_count = 0;
    unsigned int output_bytes_written = 0;
    while (original_data_length > 0){
        fill_input_array(&original_data[(input_data_count++)*input_data_length], input_data, input_data_length);
        unsigned int number_of_bytes_left_to_transfer = input_data_length;
        while(number_of_bytes_left_to_transfer > 0){
            unsigned int number_of_places_left = 4;
            char output_data[4];
            transfer_data(input_data, &number_of_bytes_left_to_transfer, output_data, &number_of_places_left);
            if(number_of_places_left == 0){
               for(int i = 0; i < 4; i++){
                    printf("%d ", output_data[i]);
                }
                number_of_places_left = 4;
            }
            printf("\n");
        }
        original_data_length -= input_data_length;

    }
        
}
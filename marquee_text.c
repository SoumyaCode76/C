#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PIXELS_PER_LINE         (50)

char text[] = "Momo and Ghettoo";
char line[PIXELS_PER_LINE];

static void rotate_array(char * s, int low, int high){
    while(low < high){
        char tmp = s[low];
        s[low] = s[high];
        s[high] = tmp;
        low++;
        high--;
    }
}

static void print_line(char * s){
    for(int i = 0; i < PIXELS_PER_LINE; i++){
        printf("%c", s[i]);
    }
    printf("\n");
    //fseek(stdout, 0, SEEK_SET);
}

int main(){
    int number_of_rotations = PIXELS_PER_LINE;
    memset(line, 0x20, PIXELS_PER_LINE);
    memcpy(line, text, strlen(text));
    while(1){
        for(int i = 0; i <= number_of_rotations; i++)
        {
            // Print the text on the screen
            print_line(line);
            /* Rotate the line by 1 place clock-wise */
            // First reverse the first n-1 elements
            rotate_array(line, 0, PIXELS_PER_LINE - 2);
            // Then reverse the array entirely
            rotate_array(line, 0, PIXELS_PER_LINE - 1);
            usleep(200*1000);
        }
    }
}
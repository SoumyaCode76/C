#include <stdio.h>
#include <string.h>

/* 
    * Applying dynamic programming approach to split a given paragraph into the list of words
    * The problem has 3 parts-
        * Determine the number of whitespaces (' ') are there
        * Create a 2D array, where the number of rows of the list is the number of whitespaces, and there will be 15 columns for max 15 characters length word
        * Then fill up the array with the words
    * For this problem, 2 functions are needed. One function will calculate number of whitespaces are available. The second function will fill-up the array.
    * An auxiliary third function will be defined, which shall print the identified words on the console
 */

unsigned int determine_number_of_whitespaces_in_paragraph(unsigned char *);
void convert_paragraph_to_wordlist(unsigned int rows, unsigned char word_list[rows][15], unsigned char * paragraph);
void print_word_list(unsigned int rows, unsigned char word_list[rows][15]);


int main(){
    unsigned char name[] = "In the realm of software development, dynamic programming stands out as a powerful technique for solving complex problems. By breaking down a problem into simpler subproblems and storing the results of these subproblems, dynamic programming ensures that each subproblem is only solved once, thus optimizing the overall computation. This approach is particularly useful in scenarios where the same subproblems are encountered multiple times, such as in the calculation of Fibonacci numbers or the optimization of knapsack problems. By leveraging dynamic programming, developers can create efficient and scalable solutions that significantly reduce computational overhead.";

    printf("Input paragraph: %s\n", name);

    unsigned int number_of_whitespaces = determine_number_of_whitespaces_in_paragraph(name);
    unsigned int number_of_words = number_of_whitespaces + 1;
    unsigned char word_list[number_of_words][15];
    convert_paragraph_to_wordlist(number_of_words, word_list, name);
    print_word_list(number_of_words, word_list);
    return 0;
    
}

/// @brief The following function does the whitespace count task
/// @param paragraph 
/// @param paragraph_length 
/// @return count of whitespaces
unsigned int determine_number_of_whitespaces_in_paragraph(unsigned char * paragraph){
    unsigned int count_of_whitespaces = 0;

    unsigned int idx = 0;
    while(paragraph[idx] != '\0'){
        if( paragraph[idx++] == ' '){
            count_of_whitespaces++;
        }
    }
    return count_of_whitespaces;
}

/// @brief The following function extracts the words and fill up in the 2D array
/// @param rows 
/// @param word_list 
/// @param paragraph 
void convert_paragraph_to_wordlist(unsigned int rows, unsigned char word_list[rows][15], unsigned char * paragraph){
    unsigned int row_idx = 0;
    unsigned int text_idx = 0;
    unsigned char * p =  paragraph;

    while( 1 ){
        /* In this conditional block, we are extracting each word if we encounter a whitespace in the paragraph */
        if( p[text_idx] == ' '){
            p[text_idx] = '\0';
            strcpy(word_list[row_idx++], p);
            p = p + text_idx + 1;
            text_idx = 0;
        }
        /* In this conditional block, we are obtaining the last word in the paragraph and terminating the loop */
        else if( p[text_idx] == '\0' ){
            strcpy(word_list[row_idx], p);
            break;
        }
        /* In this conditional block, we are incrementing the character position index in the paragraph */
        else{
            text_idx++;
        }
    }
}


/// @brief This function is an auxiliary function to print the word list prepared
/// @param rows 
/// @param word_list 
void print_word_list(unsigned int rows, unsigned char word_list[rows][15]){
    for(int idx = 0; idx < rows; idx++){
        printf("%s\n", word_list[idx]);
    }
}
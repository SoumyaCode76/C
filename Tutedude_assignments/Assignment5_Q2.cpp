/**
 * @file Assignment5_Q2.cpp
 * @brief Program to reverse a number in any base system
 * @author Student
 * @date 2026
 * @details This program takes an integer input and reverses it in a given base (default base 10)
 *          It handles both positive and negative numbers and validates user input
 */

#include <iostream>  // Standard input/output stream library
#include <string>    // String manipulation library
#include <cstring>   // C-style string operations library

using namespace std;

/**
 * @class PlayWithNumber
 * @brief A utility class for performing number manipulation operations
 * @details Provides functionality to reverse numbers in different base systems
 *          and stores the original number for reference
 */
class PlayWithNumber
{
    private:
        int num;  // Private member: stores the original integer value
    public:
        int nn;   // Public member: duplicate of num for external access
        
        /**
         * @brief Constructor to initialize PlayWithNumber object
         * @param n The integer value to be stored and manipulated
         * @details Initializes both private member 'num' and public member 'nn' with the input value
         */
        PlayWithNumber(int n)
        {
            num = n;  // Initialize private member with input parameter
            nn = n;   // Initialize public member with input parameter (stores copy for external use)
        }
        
        /**
         * @brief Reverses the number in the specified base
         * @param base The base in which to reverse the number (e.g., 10 for decimal, 2 for binary)
         * @return The reversed number in the specified base
         * @details Handles both positive and negative numbers by reversing absolute value
         *          and reapplying sign if original was negative
         */
        int reverse_number(unsigned int base)
        {
            // Store absolute value of num: make positive if negative, keep as-is if positive
            int x = (num >= 0) ? num : ((-1) * (num));
            
            // Initialize reversed variable to store the reversed number
            int reversed = 0;
            
            // Loop until all digits are processed: continue while x has digits
            while(x != 0)
            {
                // Extract last digit in the given base: (x % base) gives rightmost digit
                // Shift reversed left by one position in the base: (reversed * base)
                // Add extracted digit to reversed number: complete one iteration
                reversed = (reversed * base) + (x % base);
                
                // Remove the last digit from x: x / base removes rightmost digit
                x = x / base;
            }
            
            // Check sign of original number and apply to reversed number
            if(num < 0)
            {
                // If original number was negative, return negative reversed number
                return ((-1)*(reversed));
            }
            else
            {
                // If original number was positive, return positive reversed number
                return reversed;
            }
        }
};

/**
 * @brief Main function - Entry point of the program
 * @return int Exit status (0 for successful execution)
 * @details Prompts user for input, validates that input is a valid integer,
 *          creates PlayWithNumber object, and displays the reversed number
 */
int main(void)
{
    // Declare string variable to store user input (allows better input validation)
    string n_in;
    
    // Prompt user to enter an integer value
    cout << "Enter an integer: " << endl;
    
    // Read input from standard input and store in n_in (loop continues until successful read)
    while(!(cin >> n_in));
    
    // Validate that input contains only digits (0-9) and optional minus sign for negative numbers
    // find_first_not_of returns string::npos if all characters are valid
    if(n_in.find_first_not_of("1234567890-") == string::npos)
    {
        // Input is valid: create PlayWithNumber object with integer conversion of input string
        PlayWithNumber Number(stoi(n_in));
        
        // Display original number and its reverse in base 10 (decimal)
        cout << "Reverse of " << Number.nn <<" is: " << Number.reverse_number(10) << endl;
    }
    else
    {
        // Input contains invalid characters: display error message and exit
        cout << "Invalid input! Exiting...\n";
    }
    
    // Return 0 to indicate successful program execution
    return 0;
}

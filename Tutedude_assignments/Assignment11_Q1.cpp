/**
 * @file Assignment11_Q1.cpp
 * @brief A program to find and display all occurrences of a substring within a main string.
 * @details This program provides an interactive menu-driven interface that allows users to 
 *          find all positions where a substring occurs in a main string. It performs a 
 *          character-by-character comparison and displays the starting positions of matches.
 * @author Soumyadeep Bose
 * @date 2026
 * @version 1.0
 */

#include <iostream>

using namespace std;

/**
 * @brief Finds and prints all positions where a substring occurs in a main string.
 * @param pMain Constant pointer to the main string to be searched (C-style string).
 * @param pSub Constant pointer to the substring pattern to find (C-style string).
 * @param mainStringLength Integer representing the length of the main string.
 * @param subStringLength Integer representing the length of the substring.
 * @return void - This function outputs position information directly to stdout.
 * @note Uses nested loops for brute-force substring matching algorithm.
 * @note Time Complexity: O(mainStringLength * subStringLength)
 * 
 * @details Algorithm:
 *          1. Iterates through each position in the main string
 *          2. At each position, checks if substring matches character-by-character
 *          3. Prints the position if a complete match is found
 *          4. Displays "No occurrences found" if no matches are detected
 */
void print_substring_positions(const char* const pMain, const char* const pSub, int mainStringLength, int subStringLength)
{
    // Flag to track whether current position contains a mismatch in substring comparison
    bool match_not_found = false;
    
    // Counter to track the total number of substring matches found
    unsigned int matches_found = 0;

    // Outer loop: Iterate through each possible starting position in the main string
    // Loop condition ensures we don't exceed bounds when comparing substring
    for(int i = 0; i <= (mainStringLength - subStringLength); i++)
    {
        // Inner loop: Character-by-character comparison of substring at current position
        for(int j = 0; j < subStringLength; j++)
        {
            // Compare current character in substring with character in main string at offset i+j
            // Cast to char to ensure proper comparison
            if ( static_cast<char>( *(pMain + i + j) ) !=  static_cast<char>( *(pSub + j) )) 
            {
                    // Set flag to true if characters don't match
                    match_not_found = true;
                    // Exit inner loop early since we found a mismatch
                    break;
            }
        }
        
        // Check if substring was completely matched at this position
        if(match_not_found == false)
        {
            // Print the starting position where substring was found (0-indexed)
            cout << "Position: " << i << endl;
            // Increment counter for successful matches
            matches_found++;
        }
        else
        {
            // Reset flag for next position comparison
            match_not_found = false;
        }
    }
    
    // Check if no matches were found during the entire search
    if(matches_found == 0)
    {
        // Display message indicating substring does not exist in main string
        cout << "No occurrences found" << endl;
    }
}

/**
 * @brief Main entry point of the program.
 * @return int Exit status code (0 for normal exit, EXIT_SUCCESS for early exit).
 * @details Provides an interactive menu-driven interface for substring searching.
 *          Uses a while loop to continuously display menu until user chooses to exit.
 */
int main(void)
{
    // String variables to store user input
    string mainString, subString, choice;
    
    // Infinite loop for continuous menu display and user interaction
    while(true)
    {
        // Display the main menu with available options
        cout << "================================\n";
        cout << "1. Find occurrences of substring in main string\n";
        cout << "2. Exit\n";
        cout << "================================\n";
        
        // Read user's menu choice and validate input
        while( !(cin >> choice) );
        
        // Validate that user entered a single character from valid set ('1' or '2')
        // Condition checks: input doesn't contain invalid characters AND string has length of 1
        if( choice.find_first_not_of("12")  && string::npos && choice.length() == 1 )
        {
            // Clear the input buffer (consume newline character)
            cin.ignore(1, '\n');
            
            // Process user's menu choice
            switch(choice[0])
            {
                    // Option 1: Find substring occurrences
                    case '1':
                    {
                        // Prompt user for main string
                        cout << "Enter the main string: " << endl;
                        // Ensure user enters a non-empty main string
                        while(mainString.empty())
                        {
                            // Read entire line including spaces
                            getline(cin, mainString);
                        }
                        
                        // Prompt user for substring to search
                        cout << "Enter the substring: " << endl;
                        // Ensure user enters a non-empty substring
                        while(subString.empty())
                        {
                            // Read entire line including spaces
                            getline(cin, subString);
                        }
                        
                        // Call function to find and display all positions of substring matches
                        print_substring_positions(&mainString[0], &subString[0], mainString.length(), subString.length());
                        
                        // Clear both strings for next iteration
                        mainString = "";
                        subString = "";
                    }
                    break;
                    
                    // Option 2: Exit program
                    case '2':
                    {
                        // Display farewell message
                        cout << "Goodbye!" << endl;
                        // Terminate program with success status
                        exit(EXIT_SUCCESS);
                    }
                    break;
                    
                    // Default case: Invalid menu choice (should not occur due to validation)
                    default:
                    {
                        cout << "Please try again" << endl;
                    }
            }
        }
        else
        {
            // Invalid input: user entered characters outside '1' or '2', or multiple characters
            cout << "Please try again" << endl;
        }
    }
    return 0;
}
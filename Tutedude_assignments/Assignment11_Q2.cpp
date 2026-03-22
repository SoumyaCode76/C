/**
 * @file Assignment11_Q2.cpp
 * @brief Template-based generic linked list implementation supporting multiple data types.
 * @details This program demonstrates the use of C++ templates to create a generic LinkedList class
 *          that can store and manipulate elements of any data type (int, float, char, string).
 *          Provides a menu-driven interface for users to create linked lists and perform operations.
 * @author Soumyadeep Bose
 * @date 2026
 * @version 1.0
 */

#include <iostream>
#include <list>
using namespace std;

/**
 * @class LinkedList
 * @brief A generic template-based linked list class that works with any data type.
 * @tparam T The data type of elements that the linked list will store (int, float, char, string, etc.)
 * @details This class encapsulates the STL list container and provides simplified interface methods
 *          for adding elements and displaying the linked list contents. It uses templates to
 *          achieve type-independent implementation.
 */
template <class T>
class LinkedList
{
        private:
            // STL list container to store elements of template type T
            list<T> myList;
        public:
            /**
             * @brief Displays all elements currently in the linked list.
             * @return void
             * @details Iterates through all elements in myList using a range-based for loop
             *          and prints each element to the standard output, one per line.
             */
            void display_list(void)
            {
                // Print header message
                cout << "Elements in the linked list:" << endl;
                // Range-based for loop to iterate through each element in the list
                for(T i : myList)
                {
                    // Print the current element
                    cout << i  << endl;
                }
            }
            
            /**
             * @brief Adds a new element to the end of the linked list.
             * @param elem The element of type T to be added to the linked list.
             * @return void
             * @details Appends the provided element to the end of myList using push_back()
             *          and immediately displays the updated list contents.
             */
            void add_element_to_list(T elem)
            {
                // Add the new element to the end of the list
                myList.push_back(elem);
                // Display the updated list after adding the element
                display_list();
            }
};

/**
 * @brief Main entry point of the program.
 * @return int Exit status code (0 for normal exit, EXIT_SUCCESS for early exit).
 * @details Provides a multi-level menu-driven interface that allows users to:\n *          1. Create linked lists of different data types (int, float, char, string)
 *          2. Add elements to the selected linked list
 *          3. Display the contents of the linked list
 *          4. Exit the program
 *          Uses nested while loops and switch statements for menu navigation.
 */
int main(void)
{
    // String variables to store user's menu choices at main and sub-menu levels
    string choice, sub_choice;
    
    // Infinite loop to continuously display main menu until user exits
    while(true)
    {
        // Display the main menu with available data type options
        cout << "*****************************************************\n";
        cout << "1. Create a linked list of integers\n";
        cout << "2. Create a linked list of floats\n";
        cout << "3. Create a linked list of characters\n";
        cout << "4. Create a linked list of strings\n";
        cout << "5. Exit\n";
        cout << "*****************************************************\n";
        
        // Initialize choice to empty string for validation
        choice = "";
        
        // Input validation loop: ensure choice is single character from valid set ('1' to '5')
        while(choice.empty() || choice.length() != 1 || ( choice.find_first_not_of("12345") != string::npos ) )
        {
            // Read user's menu choice as a line
            getline(cin, choice);
        }
        
        // Process the user's main menu choice
        switch(choice[0])
        {
            // Case 1: Create and manage a linked list of integers
            case '1':
            {
                    // Instantiate a LinkedList template with int data type
                    LinkedList<int> ll;
                    
                    // Inner loop for handling integer linked list operations
                    while(true)
                    {
                        // Display submenu for integer list operations
                        cout << "___________________________________________________\n";
                        cout << "1. Add an element to the list\n";
                        cout << "2. Print the list\n";
                        cout << "3. Return to main menu\n";
                        cout << "___________________________________________________\n";
                        
                        // Initialize sub_choice for validation
                        sub_choice = "";
                        
                        // Input validation: ensure sub_choice is single character from valid set ('1' to '3')
                        while(sub_choice.empty() || sub_choice.length() != 1 || ( sub_choice.find_first_not_of("123") != string::npos ) )
                        {
                            // Read user's submenu choice
                            getline(cin, sub_choice);
                        }
                        
                        // Process the submenu choice for integer operations
                        {
                            // Submenu option 1: Add integer element to list
                            if(sub_choice[0] == '1')
                            {
                                // String variable to temporarily store user input as string
                                string number;
                                // Prompt user to enter an integer
                                cout << "Enter the integer to add\n";
                                // Do-while loop for input validation
                                do
                                {
                                    // Read input as string
                                    cin >> number;
                                }while(cin.flags() == false || (number.find_first_not_of("1234567890-") != string::npos) );
                                // Convert string to integer using stoi() and add to list
                                ll.add_element_to_list(stoi(number));
                            }
                            // Submenu option 2: Display all elements in the integer list
                            else if(sub_choice[0] == '2')
                            {
                                // Call display_list() to print all integer elements
                                ll.display_list();
                            }
                            // Submenu option 3: Return to main menu
                            else if(sub_choice[0] == '3')
                            {
                                // Print return message
                                cout << "Returning to main menu\n";
                                // Break from inner while loop to return to main menu
                                break;                            
                            }
                            // Invalid submenu choice
                            else
                            {
                                // Inform user of invalid choice
                                cout << "Invalid choice given. Please try again!" << endl;
                            }
                        }
                    }
             }
             break;

            // Case 2: Create and manage a linked list of floats
            case '2':
            {
                // Instantiate a LinkedList template with float data type
                LinkedList<float> ll;
                
                // Inner loop for handling float linked list operations
                while(true)
                {
                    // Display submenu for float list operations
                    cout << "___________________________________________________\n";
                    cout << "1. Add an element to the list\n";
                    cout << "2. Print the list\n";
                    cout << "3. Return to main menu\n";
                    cout << "___________________________________________________\n";
                    
                    // Initialize sub_choice for validation
                    sub_choice = "";
                    
                    // Input validation: ensure sub_choice is single character from valid set ('1' to '3')
                    while(sub_choice.empty() || sub_choice.length() != 1 || ( sub_choice.find_first_not_of("123") != string::npos ) )
                    {
                        // Read user's submenu choice
                        getline(cin, sub_choice);
                    }
                    
                    // Process the submenu choice for float operations
                    // Submenu option 1: Add float element to list
                    if(sub_choice[0] == '1')
                    {
                        // String variable to temporarily store user input as string
                        string number;
                        // Prompt user to enter a float
                        cout << "Enter the float to add\n";
                        // Do-while loop for input validation (checks for valid float characters)
                        do
                        {
                            // Read input as string
                            cin >> number;
                        }while(cin.flags() == false || (number.find_first_not_of("1234567890-.") != string::npos) );
                        // Convert string to float using stof() and add to list
                        ll.add_element_to_list(stof(number));
                    }
                    // Submenu option 2: Display all elements in the float list
                    else if(sub_choice[0] == '2')
                    {
                        // Call display_list() to print all float elements
                        ll.display_list();
                    }
                    // Submenu option 3: Return to main menu
                    else if(sub_choice[0] == '3')
                    {
                        // Print return message
                        cout << "Returning to main menu\n";
                        // Break from inner while loop to return to main menu
                        break;
                    }
                    // Invalid submenu choice
                    else
                    {
                        // Inform user of invalid choice
                        cout << "Invalid choice given. Please try again!" << endl;
                    }
                }
             }
             break;             
            // Case 3: Create and manage a linked list of characters
            case '3':
            {
                // Instantiate a LinkedList template with char data type
                LinkedList<char> ll;
                
                // Inner loop for handling character linked list operations
                while(true)
                {
                    // Display submenu for character list operations
                    cout << "___________________________________________________\n";
                    cout << "1. Add an element to the list\n";
                    cout << "2. Print the list\n";
                    cout << "3. Return to main menu\n";
                    cout << "___________________________________________________\n";
                    
                    // Initialize sub_choice for validation
                    sub_choice = "";
                    
                    // Input validation: ensure sub_choice is single character from valid set ('1' to '3')
                    while(sub_choice.empty() || sub_choice.length() != 1 || ( sub_choice.find_first_not_of("123") != string::npos ) )
                    {
                        // Read user's submenu choice
                        getline(cin, sub_choice);
                    }
                    
                    // Process the submenu choice for character operations
                    // Submenu option 1: Add character element to list
                    if(sub_choice[0] == '1')
                    {
                        // String variable to temporarily store user input (will extract first character)
                        string number;
                        // Prompt user to enter a character
                        cout << "Enter the character to add\n";
                        // Do-while loop for input validation (ensures input is not empty)
                        do
                        {
                            // Read input as string
                            cin >> number;
                        }while(cin.flags() == false || number.empty() == true );
                        // Extract first character from string and add to char list
                        ll.add_element_to_list(number[0]);
                    }
                    // Submenu option 2: Display all elements in the character list
                    else if(sub_choice[0] == '2')
                    {
                        // Call display_list() to print all character elements
                        ll.display_list();
                    }
                    // Submenu option 3: Return to main menu
                    else if(sub_choice[0] == '3')
                    {
                        // Print return message
                        cout << "Returning to main menu\n";
                        // Break from inner while loop to return to main menu
                        break;
                    }
                    // Invalid submenu choice
                    else
                    {
                        // Inform user of invalid choice
                        cout << "Invalid choice given. Please try again!" << endl;
                    }
                }
             }
             break;
             
            // Case 4: Create and manage a linked list of strings
            case '4':
            {
                // Instantiate a LinkedList template with string data type
                LinkedList<string> ll;
                
                // Inner loop for handling string linked list operations
                while(true)
                {
                    // Display submenu for string list operations
                    cout << "___________________________________________________\n";
                    cout << "1. Add an element to the list\n";
                    cout << "2. Print the list\n";
                    cout << "3. Return to main menu\n";
                    cout << "___________________________________________________\n";
                    
                    // Initialize sub_choice for validation
                    sub_choice = "";
                    
                    // Input validation: ensure sub_choice is single character from valid set ('1' to '3')
                    while(sub_choice.empty() || sub_choice.length() != 1 || ( sub_choice.find_first_not_of("123") != string::npos ) )
                    {
                        // Read user's submenu choice
                        getline(cin, sub_choice);
                    }
                    
                    // Process the submenu choice for string operations
                    // Submenu option 1: Add string element to list
                    if(sub_choice[0] == '1')
                    {
                        // String variable to store user input string
                        string number;
                        // Prompt user to enter a string
                        cout << "Enter the string to add\n";
                        // Do-while loop for input validation (ensures input is not empty)
                        do
                        {
                            // Read input as string
                            cin >> number;
                        }while(cin.flags() == false || number.empty() == true );
                        // Add the string to the string list
                        ll.add_element_to_list(number);
                    }
                    // Submenu option 2: Display all elements in the string list
                    else if(sub_choice[0] == '2')
                    {
                        // Call display_list() to print all string elements
                        ll.display_list();
                    }
                    // Submenu option 3: Return to main menu
                    else if(sub_choice[0] == '3')
                    {
                        // Print return message
                        cout << "Returning to main menu\n";
                        // Break from inner while loop to return to main menu
                        break;
                    }
                    // Invalid submenu choice
                    else
                    {
                        // Inform user of invalid choice
                        cout << "Invalid choice given. Please try again!" << endl;
                    }
                }
             }
             break;
             
             // Case 5: Exit the program
             case '5':
             {
                // Display farewell message
                cout << "Goodbye!\n";
                // Terminate program with success status
                exit(EXIT_SUCCESS);
             }
             break;
             
             // Default case: Invalid main menu choice (should not occur due to validation)
             default:
            {
                // Inform user of invalid choice
                cout << "Please try again" << endl;
            }             
        }
    }
    // Return 0 to indicate successful program termination
    return 0;
}
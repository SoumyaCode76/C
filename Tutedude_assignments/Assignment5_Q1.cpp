/**
 * @file Assignment5_Q1.cpp
 * @brief Student Details Management System
 * @details A console-based application that manages student records with a fixed-capacity table.
 *          Users can add student details, check available space, display all entries, and exit.
 * @author Student
 * @date 2026
 */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define STUDENT_TABLE_CAPACITY      (2U)  /**< Maximum capacity of the student table */

/**
 * @struct tStudentDetails
 * @brief Structure to hold individual student information
 * @details Contains student ID, name, age, and grade information
 */
typedef struct
{
    unsigned int ID;           /**< Student ID number (unsigned integer) */
    string Name;               /**< Student name (string of 3+ characters) */
    unsigned int Age;          /**< Student age (unsigned integer) */
    unsigned char Grade;       /**< Student grade (A-F) */
}tStudentDetails;

/**
 * @struct tStudentDetailsTable
 * @brief Structure to manage a table of student records
 * @details Contains an array of student details and tracks available entries
 */
typedef struct
{
    tStudentDetails students[STUDENT_TABLE_CAPACITY];  /**< Array of student records */
    unsigned int entries_available;                     /**< Count of available slots in the table */
}tStudentDetailsTable;

/** @brief Global student table instance */
tStudentDetailsTable StudentTable;

/**
 * @enum Menu choice enumeration
 * @brief Defines valid menu selections for user interaction
 */
enum
{
    CHOICE1 = 1U,  /**< Choice 1: Enter student details */
    CHOICE2,       /**< Choice 2: Enquire available entries */
    CHOICE3,       /**< Choice 3: Display student table */
    CHOICE4        /**< Choice 4: Exit application */
};

/* Problem formulation:
    * Display a menu for the user, with options: 1 (enter student details), 2 (enquire how many more entries can be made), 
    3 (display the table), 4 (exit)
    * Choice 1: user enters the details. After the details are verified for syntax, the details will be filled in the table.
    * Choice 2: user asks for how many more entries can be made to the table.
    * Choice 3: user asks to display the table in current state.
    * Choice 4: exit the application
    * Constraints:
    * Choice 1: user should be informed how many entries available. If no space available, reject the user request. 
    * More conveniently, when the capacity is reached, do not display Choice 1 and 2 anymore. Rather display, table is full.
    * Advanced design: Let the user drop one or more entries specified by the ID numbers, to create vacancies.
    * Choice 2: should return how many more new entries can be made. If 0, this choice must not be displayed to prevent abuse.
    * Choice 3: print the details in vertical order starting from 1st student, ending till the last details filled, not the entire table.
    * Choice 4: display on-screen what the user needs to enter to exit from the app.
    
   Test cases:
    * Common:
        - all provided choices must trigger the respective response handlers and perform the correct operation if inputs are valid.
        - user enters no input. no reaction from the app to be given.
        - user enters non-numeric inputs for the choices, the app should reject and restart the app.
    * Choice 1:
        - user enters non-numeric characters for age, id. app should reject and restart the app.
        - user enters negative number for ID and Age, app should reject and restart.
        - user enters grade other than A, B, C, D, E, F, shall be rejected and restart.
        - if no further entries available, this choice must not be displayed. Rather a relevant message should be displayed.
    * Choice 2:
        - if no further entries available, this choice must not be displayed. Rather a relevant message should be displayed.
    * Choice 3:
        - No such negative test cases
    * Choice 4:
        - No such negative test cases
*/

/**
 * @brief Fills student details into the student table
 * @param id The student ID number (positive integer)
 * @param name The student name (string of 3+ characters)
 * @param age The student age (positive integer)
 * @param grade The student grade (A-F)
 * @return void
 * @details Adds a new student record to the table if space is available.
 *          Displays a success message on successful entry or an error message if table is full.
 * @see tStudentDetails, tStudentDetailsTable
 */
void fill_student_details(unsigned int id, string name, unsigned int age, unsigned char grade)
{
    // Check if there is at least one empty slot available in the student table
    if(StudentTable.entries_available > 0)
    {
        // Calculate index of the next available slot and initialize it with the provided student details
        StudentTable.students[STUDENT_TABLE_CAPACITY - StudentTable.entries_available] = {
            .ID = id,              // Assign the student ID
            .Name = name,          // Assign the student name
            .Age = age,            // Assign the student age
            .Grade = grade         // Assign the student grade
        };
        // Decrement the available slots counter after adding a new entry
        StudentTable.entries_available--;
        // Inform the user that the entry was successful
        cout << "Details successfully entered\n";
    }
    else
    {
        // Inform the user that the table is full and no more entries can be added
        cout << "No more space available\n";
    }
}

/**
 * @brief Displays the main menu to the user
 * @return void
 * @details Shows menu options based on table capacity status.
 *          If space is available: shows options 1-4 (add, enquire, display, exit).
 *          If table is full: shows only options 3-4 (display, exit).
 */
void display_menu(void)
{
    // Check if space is still available in the table
    if(StudentTable.entries_available > 0)
    {
        // Display the full menu with all four options when slots are available
        cout << "========================================" << endl;
        cout << "1>Enter student details (ID, Name, Age, Grade)" << endl;
        cout << "2>Enquire how many more entries can be entered\n";
        cout << "3>Display the student details entered till now\n";
        cout << "4>Exit\n";
        cout << "========================================" << endl;
    }
    else
    {
        // Display limited menu (options 3 and 4 only) when table is full
        cout << "========================================" << endl;
        cout << "Table is full\n";
        cout << "3>Display the student details entered till now\n";
        cout << "4>Exit\n";
        cout << "========================================" << endl;
    }
}

/**
 * @brief Executes the user's menu choice
 * @param ch The choice selected by the user (1-4)
 * @return void
 * @details Handles different menu choices:
 *          - CHOICE1: Prompts user for student details with input validation
 *          - CHOICE2: Displays number of available entries
 *          - CHOICE3: Displays all entered student records
 *          - CHOICE4: Exits the application
 *          Includes comprehensive input validation for ID, name, age, and grade.
 * @see execute_choices, fill_student_details, CHOICE1, CHOICE2, CHOICE3, CHOICE4
 */
void execute_choices(int ch)
{
    if(StudentTable.entries_available > 0)
    {
        switch(ch)
        {
            case CHOICE1:
            {
                // Initialize a string array to hold user input for all four fields
                string inputs[4];
                // Initialize integer variables to store validated ID and age
                int id = 0, age = 0;
                // Initialize string variable to store the student name
                string name;
                // Initialize character variable to store the single-character grade
                char grade;
                
                // ===== INPUT 1: Student ID =====
                cout << "\nEnter the ID (only positive integer numbers allowed)" << endl;
                // Loop until valid positive integer ID is entered
                while(true)
                {
                    // Wait for user input and read the string
                    while(!(cin >> inputs[0]));
                    // Skip if input is empty (no characters entered)
                    if(inputs[0].empty())
                    {
                        continue;
                    }
                    // Validate that input contains only numeric digits (0-9)
                    else if(inputs[0].find_first_not_of("1234567890") && inputs[0] != "0")
                    {
                        // Convert the validated string to integer and store in id
                        id = stoi(inputs[0]);
                        // Exit the validation loop on successful input
                        break;
                    }
                    else
                    {
                        // Display error message for invalid ID format
                        cout << "Invalid input format for ID. Please try again\n";
                        continue;
                    }
                }
                
                // ===== INPUT 2: Student Name =====
                cout << "\nEnter the name (3 or more characters)" << endl;
                // Loop until a valid name (3+ characters) is entered
                while(true)
                {
                    // Read the entire line including spaces using getline()
                    getline(cin, inputs[1]);
                    // Skip if input is empty
                    if(inputs[1].empty())
                    {
                        continue;
                    }
                    // Validate that the name has at least 3 characters
                    else if(inputs[1].length() >= 3)
                    {
                        // Store the validated name
                        name = inputs[1];
                        // Exit the validation loop on successful input
                        break;
                    }
                    else
                    {
                        // Display error message if name is too short
                        cout << "Invalid number of characters entered. Please try again.\n";
                        continue;
                    }
                }
                
                // ===== INPUT 3: Student Age =====
                cout << "\nEnter the age" << endl;
                // Loop until valid positive integer age is entered
                while(true)
                {
                    // Wait for user input and read the string
                    while(!(cin >> inputs[2]));
                    // Skip if input is empty
                    if(inputs[2].empty())
                    {
                        continue;
                    }
                    // Validate that input contains only numeric digits
                    else if(inputs[2].find_first_not_of("1234567890") && inputs[2] != "0")
                    {
                        // Convert the validated string to integer and store in age
                        age = stoi(inputs[2]);
                        // Exit the validation loop on successful input
                        break;
                    }
                    else
                    {
                        // Display error message for invalid age format
                        cout << "Invalid input format for age. Please try again\n";
                        continue;
                    }
                }
                
                // ===== INPUT 4: Student Grade =====
                cout << "\nEnter the grade (Allowed: A, B, C, D, E, F)" << endl;
                // Loop until a valid grade (single letter A-F) is entered
                while(true)
                {
                    // Wait for user input and read the string
                    while(!(cin >> inputs[3]));
                    // Skip if input is empty
                    if(inputs[3].empty())
                    {
                        continue;
                    }
                    // Validate that input is a single character and one of A-F
                    else if(inputs[3].find_first_not_of("ABCDEF") && inputs[3].length() == 1U)
                    {
                        // Extract the first character and store it as the grade
                        grade = inputs[3][0];
                        // Exit the validation loop on successful input
                        break;
                    }
                    else
                    {
                        // Display error message for invalid grade format
                        cout << "Invalid input format for grade. Please try again\n";
                        continue;
                    }
                }
                
                // Call the function to add the validated student details to the table
                fill_student_details(static_cast<unsigned int>(id), name, static_cast<unsigned int>(age), static_cast<unsigned char>(grade));
            }
            break;
            case CHOICE2:
            {
                // Display the current number of available slots in the student table
                cout << "Number of entries available: " << StudentTable.entries_available << endl;
            }
            break;
        }
    }
    if(ch == CHOICE3 || ch == CHOICE4)
    {
        switch(ch)
        {
            case CHOICE3:
            {
                // Loop through all entries that have been filled (from index 0 to number of entries)
                for(unsigned int i = 0; i < (STUDENT_TABLE_CAPACITY - StudentTable.entries_available); i++)
                {
                    // Display the student ID for the current record
                    cout << "Student " << StudentTable.students[i].ID << ":\n";
                    // Display the student name for the current record
                    cout << "Name: " << StudentTable.students[i].Name << "\n";
                    // Display the student age for the current record
                    cout << "Age: " << StudentTable.students[i].Age << "\n";
                    // Display the student grade for the current record
                    cout << "Grade: " << StudentTable.students[i].Grade << "\n";
                    // Display a separator line between student records
                    cout << "-------------------------------------\n";
                }
            }
            break;
            case CHOICE4:
            {
                // Display goodbye message to the user
                cout << "Goodbye!" << endl;
                // Terminate the program with successful exit status
                exit(EXIT_SUCCESS);
            }
            break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

/**
 * @brief Main application loop
 * @return void
 * @details Initializes the student table and runs the main menu loop.
 *          Repeatedly displays menu, accepts user choice, and executes corresponding action.
 *          Validates menu choices and handles invalid input by prompting again.
 * @see display_menu, execute_choices, fill_student_details
 */
void app_main(void)
{
    // Declare string variable to hold the user's menu choice input
    string choice;
    // Declare integer variable to store the converted menu choice
    int ch = 0;
    // Initialize the student table by setting maximum available slots equal to table capacity
    StudentTable.entries_available = STUDENT_TABLE_CAPACITY;
    
    // Infinite loop to continuously display menu and process user choices until exit
    while(true)
    {
        // Display the current menu options based on table capacity status
        display_menu();
        // Read the user's choice from input and wait if no input is available
        while(!(cin >> choice));
        // Check if the input is empty or if there was a stream error, skip to next iteration if so
        if(choice.empty() == true || cin.flags() == false)
        {
            continue;
        }
        
        // Check if space is still available in the table (menu shows options 1-4)
        if(StudentTable.entries_available > 0)
        {
            // Validate that choice is a single character and one of 1, 2, 3, or 4
            if(choice.find_first_not_of("1234") && choice.length() == 1)
            {
                // Convert the validated choice string to an integer
                ch = stoi(choice);
            }
            else
            {
                // Display error if choice is invalid and prompt user to try again
                cout << "Invalid choice. Please try again!" << endl;
                // Skip to the next menu iteration
                continue;
            }
        }
        else
        {
            // Table is full, so validate that choice is only 3 or 4
            if(choice.find_first_not_of("34") && choice.length() == 1)
            {
                // Convert the validated choice string to an integer
                ch = stoi(choice);
            }
            else
            {
                // Display error if choice is invalid and prompt user to try again
                cout << "Invalid choice. Please try again!" << endl;
                // Skip to the next menu iteration
                continue;
            }            
        }

        // Execute the function corresponding to the user's validated choice
        execute_choices(ch);
    }
}

/**
 * @brief Entry point of the application
 * @return int Exit status (0 on successful completion)
 * @details Initializes and starts the student management system application.
 * @see app_main
 */
int main(void)
{
    // Call the main application function to start the student management system
    app_main();
    // Return 0 to indicate successful program termination
    return 0;
}

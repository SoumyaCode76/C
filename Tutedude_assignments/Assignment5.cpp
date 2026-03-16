#define Q1                      (1)
#define Q2                      (0)
#define Q3                      (0)

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#if (Q1 == 1)

#define STUDENT_TABLE_CAPACITY      (2U)

typedef struct
{
    unsigned int ID;
    string Name;
    unsigned int Age;
    unsigned char Grade;
}tStudentDetails;

typedef struct
{
    tStudentDetails students[STUDENT_TABLE_CAPACITY];
    unsigned int entries_available;
}tStudentDetailsTable;

tStudentDetailsTable StudentTable;

enum
{
    CHOICE1 = 1U,
    CHOICE2,
    CHOICE3,
    CHOICE4
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

void fill_student_details(unsigned int id, string name, unsigned int age, unsigned char grade)
{
    if(StudentTable.entries_available > 0)
    {
        StudentTable.students[STUDENT_TABLE_CAPACITY - StudentTable.entries_available] = {
            .ID = id,
            .Name = name,
            .Age = age,
            .Grade = grade
        };
        StudentTable.entries_available--;
        cout << "Details successfully entered\n";
    }
    else
    {
        cout << "No more space available\n";
    }
}

void display_menu(void)
{
    if(StudentTable.entries_available > 0)
    {
        cout << "========================================" << endl;
        cout << "1>Enter student details (ID, Name, Age, Grade)" << endl;
        cout << "2>Enquire how many more entries can be entered\n";
        cout << "3>Display the student details entered till now\n";
        cout << "4>Exit\n";
        cout << "========================================" << endl;
    }
    else
    {
        cout << "========================================" << endl;
        cout << "Table is full\n";
        cout << "3>Display the student details entered till now\n";
        cout << "4>Exit\n";
        cout << "========================================" << endl;
    }
}

void execute_choices(int ch)
{
    if(StudentTable.entries_available > 0)
    {
        switch(ch)
        {
            case CHOICE1:
            {
                string inputs[4];
                int id = 0, age = 0;
                string name;
                char grade;
                cout << "\nEnter the ID (only positive integer numbers allowed)" << endl;
                while(true)
                {
                    while(!(cin >> inputs[0]));
                    if(inputs[0].empty())
                    {
                        continue;
                    }
                    else if(inputs[0].find_first_not_of("1234567890") && inputs[0] != "0")
                    {
                        id = stoi(inputs[0]);
                        break;
                    }
                    else
                    {
                        cout << "Invalid input format for ID. Please try again\n";
                        continue;
                    }
                }
                cout << "\nEnter the name (3 or more characters)" << endl;
                while(true)
                {
                    // while(!(cin >> inputs[1]));
                    getline(cin, inputs[1]);
                    if(inputs[1].empty())
                    {
                        continue;
                    }
                    else if(inputs[1].length() >= 3)
                    {
                        name = inputs[1];
                        break;
                    }
                    else
                    {
                        cout << "Invalid number of characters entered. Please try again.\n";
                        continue;
                    }
                }
                cout << "\nEnter the age" << endl;
                while(true)
                {
                    while(!(cin >> inputs[2]));
                    if(inputs[2].empty())
                    {
                        continue;
                    }
                    else if(inputs[2].find_first_not_of("1234567890") && inputs[2] != "0")
                    {
                        age = stoi(inputs[2]);
                        break;
                    }
                    else
                    {
                        cout << "Invalid input format for age. Please try again\n";
                        continue;
                    }
                }
                cout << "\nEnter the grade (Allowed: A, B, C, D, E, F)" << endl;
                while(true)
                {
                    while(!(cin >> inputs[3]));
                    if(inputs[3].empty())
                    {
                        continue;
                    }
                    else if(inputs[3].find_first_not_of("ABCDEF") && inputs[3].length() == 1U)
                    {
                        grade = inputs[3][0];
                        break;
                    }
                    else
                    {
                        cout << "Invalid input format for grade. Please try again\n";
                        continue;
                    }
                }       
                fill_student_details(static_cast<unsigned int>(id), name, static_cast<unsigned int>(age), static_cast<unsigned char>(grade));
            }
            break;
            case CHOICE2:
            {
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
                for(unsigned int i = 0; i < (STUDENT_TABLE_CAPACITY - StudentTable.entries_available); i++)
                {
                    cout << "Student " << StudentTable.students[i].ID << ":\n";
                    cout << "Name: " << StudentTable.students[i].Name << "\n";
                    cout << "Age: " << StudentTable.students[i].Age << "\n";
                    cout << "Grade: " << StudentTable.students[i].Grade << "\n";
                    cout << "-------------------------------------\n";
                }
            }
            break;
            case CHOICE4:
            {
                cout << "Goodbye!" << endl;
                exit(EXIT_SUCCESS);
            }
            break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

void app_main(void)
{
    string choice;
    int ch = 0;
    StudentTable.entries_available = STUDENT_TABLE_CAPACITY;    
    while(true)
    {
        display_menu();
        while(!(cin >> choice));
        if(choice.empty() == true || cin.flags() == false)
        {
            continue;
        }
        if(StudentTable.entries_available > 0)
        {
            if(choice.find_first_not_of("1234") && choice.length() == 1)
            {
                ch = stoi(choice);
            }
            else
            {
                cout << "Invalid choice. Please try again!" << endl;
                continue;
            }
        }
        else
        {
            if(choice.find_first_not_of("34") && choice.length() == 1)
            {
                ch = stoi(choice);
            }
            else
            {
                cout << "Invalid choice. Please try again!" << endl;
                continue;
            }            
        }

        execute_choices(ch);
    }
}

int main(void)
{
    app_main();
    return 0;
}



#elif (Q2 == 1)

/* Define a class representing stack */
/* Define two operations: push and pop. */
/* For push, overload the operator + */
/* For pop, overload the operator -  */
/* Ensure the stack is circular by design */

class tStack
{
    private:
        unsigned int noOfElements;
        int* arr;
        unsigned int count;
    public:
        tStack(int* arr)
        {
            /* Default stack to contain 50 elements */
            tStack::arr = arr;
            tStack::noOfElements = 50;
            tStack::count = 0;
            memset(tStack::arr, 0, tStack::noOfElements);
        }
        tStack(int* arr, unsigned int noOfElements)
        {
            /* Define number of elements required for the stack */
            tStack::arr = arr;
            tStack::noOfElements = noOfElements;
            tStack::count = 0;
            memset(tStack::arr, 0, tStack::noOfElements);
        }

        void display_stack(void)
        {
            if(count == 0)
            {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack elements: ";
            for(int i = 0; i < count; i++)
            {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }

        void operator +(const int& val)
        {
            arr[count] = val;
            count++;
            count %= noOfElements;
        }

        void operator -(int& val)
        {
            if(count == 0)
            {
                count = noOfElements - 1;
            }
            else
            {
                count--;
            }
            val = arr[count];
        }
};

int main(void)
{
    int* arr = new int[10];
    tStack stack1(arr, 10);
    stack1.display_stack();    
    stack1 + 20;
    stack1.display_stack();    
    stack1 + 60;
    stack1.display_stack();    
    int val = 0;
    stack1 - val;
    cout << "Value popped: " << val <<endl;
    stack1.display_stack();    
    return 0;
}

#elif (Q3 == 1)
#include <limits>

int GCD_of_two_numbers(int x, int y)
{
    int rem = 0;
    int a = 0, b = 0;
    if(x > y)
    {
        a = y;
        b = x;
    }
    else
    {
        a = x;
        b = y;
    }
    if(a == b)
    {
        return a;
    }
    else if( (b % a) == 0)
    {
        return a;
    }
    else
    {
        while(1)
        {
            rem = b % a;
            if(rem != 0)
            {
                b = a;
                a = rem;
            }           
            else
            {
                return a;
            } 
        }

    }
}
int main(void)
{
    double x_in = 0.0, y_in = 0.0;
    int x = 0, y = 0;
    cout << "Please enter two integers. (Note: Decimal numbers will be rounded down to the previous integers)" << endl;
    while(!(cin >> x_in >> y_in))
    {
        cout << "Invalid input provided. Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    x = static_cast<int>(x_in);
    y = static_cast<int>(y_in);
    cout << "GCD of " << x << " and " << y << " is: " << GCD_of_two_numbers(x, y) << endl;
    return 0;
}
#endif
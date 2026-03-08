/* 
    Question 1:
    Write a C++ program to create a simple calculator using the switch statement. The calculator should allow the user to perform basic arithmetic operations (addition, subtraction, multiplication, division). The program should prompt the user to choose an operation, and then input the numbers to be calculated.
    Requirements:
    1. The program should use a switch statement to perform different operations.
    2. Handle division by zero with an appropriate message.
    3. The program should allow multiple operations until the user decides to quit.
    4. Ensure that the program performs integer calculations only.
    5. Use proper input validation to handle incorrect data.
*/

#include <iostream>
#include <limits>

using namespace std;

typedef enum
{
    READY = 0U,
    BUSY,
    EXIT
}tSystemState;

typedef enum
{
    NONE = 0U,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    QUIT
}tOpChoices;

typedef struct
{
    tSystemState prev_state;
    tSystemState curr_state;
}tState;

tState sys_state = {READY, READY};
tOpChoices op_to_perform = NONE;
unsigned char choice_lut[6] = {0, 'a', 'b', 'c', 'd', 'e'};

tOpChoices get_choice_key(const unsigned char &choice)
{
    for(int i = 0; i < sizeof(choice_lut); i++)
    {
        if(choice == choice_lut[i])
        {
            return static_cast<tOpChoices>(i);
        }
    }
    return NONE;
}

void set_system_state(tState &sys_state, tSystemState req_state)
{
    if(sys_state.curr_state != req_state)
    {
        sys_state.prev_state = sys_state.curr_state;
        sys_state.curr_state = req_state;
    }
}

void receive_inputs(tOpChoices &choice, int &x, int &y)
{
    unsigned char c_in = 0;
    do
    {
        while(!(cin >> c_in))
        {
            cout << "Invalid choice provided. Please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        choice = get_choice_key(c_in);
        if(choice == NONE)
        {
            cout << "Invalid input character provided. Please try again..." << endl;
        }
    }while(choice == NONE);
    if(choice != QUIT)
    {
        double x_in, y_in;
        while(!(cin >> x_in >> y_in))
        {
            cout << "Invalid input provided. Please try again..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }        
        x = static_cast<int>(x_in);
        y = static_cast<int>(y_in);
    }
}

void validate_inputs(const tOpChoices &choice, const int &x, const int &y)
{    
    if(choice == QUIT)
    {
        cout << "Goodbye!" << endl;
        set_system_state(sys_state, EXIT);
        op_to_perform = NONE;
    }
    else
    {
        int entered_choice = static_cast<int>(choice);
        switch(choice)
        {
            case ADDITION:
            case SUBTRACTION:
            case MULTIPLICATION:
            {
                cout << "Inputs are valid. Processing..." << endl;
                set_system_state(sys_state, BUSY);
                op_to_perform = static_cast<tOpChoices>(choice);            
            }
            break;
            case DIVISION:
            {
                if(y == 0)
                {
                    cout << "Division by zero not allowed. Please try again..." << endl;
                    set_system_state(sys_state, READY);
                    op_to_perform = NONE;
                }
                else
                {
                    cout << "Inputs are valid. Processing..." << endl;
                    set_system_state(sys_state, BUSY);
                    op_to_perform = static_cast<tOpChoices>(choice);            
                }                
            }
            break;
            default:
            {
                cout << "Incorrect choice made! Choose again" << endl;
            }
        }
    }
}

void perform_calculation(const tOpChoices &choice, const int &x, const int &y)
{
    tOpChoices chosen_operation = static_cast<tOpChoices>(choice);
    static bool operation_ongoing = false;
    if(operation_ongoing == false)
    {
        operation_ongoing = true;
        cout << "Result: ";
        switch(chosen_operation)
        {
            case ADDITION:
                cout << (x + y) << endl;
                operation_ongoing = false;
                break;
            case SUBTRACTION:
                cout << (x - y) << endl;
                operation_ongoing = false;
                break;
            case MULTIPLICATION:
                cout << (x * y) << endl;
                operation_ongoing = false;
                break;
            case DIVISION:
                cout << (x / y) << endl;
                operation_ongoing = false;
                break;
        }
    }
}

int main(void)
{
    tOpChoices choice = NONE;
    int x = 0, y = 0;
    unsigned int no_of_inputs_received = 0;
    bool display_menu = true;
    while(1)
    {
        if(display_menu == true)
        {
            display_menu = false;
            cout << "=========================================" << endl;
            cout << "Syntax of passing the arguments\n" << "<choice> <first number> <second number>" << endl; 
            cout << "Choose any one from the following options" << endl;
            cout << "a <first number> + <second number>" << endl;
            cout << "b <first number> - <second number>" << endl;
            cout << "c <first number> * <second number>" << endl;
            cout << "d <first number> / <second number>" << endl;
            cout << "e(Quit)" << endl;
            cout << "=========================================" << endl;            
        }
        // If current state is READY
        if(sys_state.curr_state == READY)
        {
            receive_inputs(choice, x, y);
            validate_inputs(choice, x, y);
            if(sys_state.curr_state == READY)
            {
                display_menu = true;
            }
        }
        else if(sys_state.curr_state == BUSY)
        {
            perform_calculation(choice, x, y);
            set_system_state(sys_state, READY);
            display_menu = true;
        }
        else
        {
            // If system state is set to EXIT, quit running the program
            break;
        }
    }
    return 0;
}
/* 
    Question 2:
    Write a C++ program to check if a given integer is even, odd, or neither (0). The program should take an integer as input and determine its parity.
    Requirements:
    1. The program should ask the user to input an integer.
    2. If the integer is even, print 'Even'.
    3. If the integer is odd, print 'Odd'.
    4. If the integer is 0, print 'Neither'.
    5. The program should handle both positive and negative integers.
*/

/* 
    Solution:
    User is asked to enter a number. After the user enters the number and presses ENTER, the app makes the decision and prints it.
    After printing the result, the app prompts the user again, until the user enters E and presses ENTER.
    Invalid inputs: characters, floating point numbers
*/

#include <iostream>
#include <string>

using namespace std;

void display_menu(bool display)
{
    if(display == true)
    {
        cout << "Syntax: <integer number>\n";
        cout << "Enter q to quit" << endl;
    }
}

void process_even_odd(const int &x)
{
    cout << "Result: ";
    if(x == 0)
    {
        cout << "Neither" << endl;
    }
    else if((x % 2) == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
}

int main(void)
{
    string input;
    double x_in = 0.0;
    bool show_menu = true;
    int x;
    while(1)
    {
        if(show_menu == true)
        {
            display_menu(show_menu);
            show_menu = false;
        }
        getline(cin, input);
        if(input[0] == 'Q' || input[0] == 'q')
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if((input.find_first_not_of("0123456789-") == string::npos) && input != "")
        {
            x = stoi(input);
            process_even_odd(x);
            show_menu = true;
        }
        else
        {
            cout << "Invalid input. Please try again" << endl;
        }
    }
}

#define Q1                      (0)
#define Q2                      (0)
#define Q3                      (1)

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#if (Q1 == 1)
bool eligible_to_vote(unsigned int age)
{
    return (age >= 18) ? true : false;
}

int main(void)
{
    double age_in;
    while(true)
    {
        cout << "\n\nSyntax: <Enter age> (Enter -1 to exit)\n";
        cout << "Age: ";
        while(!(cin >> age_in))
        {
            cout << "Invalid input. Please try again!" << endl;
            continue;
        }
        int age = static_cast<int>(age_in);
        if(age == -1)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if(age < 0 && age != -1)
        {
            cout << "Age cannot be negative. Please try again!" << endl;
            continue;
        }
        else
        {
            if(true == eligible_to_vote(age))
            {
                cout << "Eligible to vote" << endl;
            }
            else
            {
                cout << "Not eligible to vote" << endl;
            }
        }
    }
}
#elif (Q2 == 1)
#include <cmath>

#define NUMBER_OF_SUPPORTED_OPERATIONS          (5)

enum
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENT
};

double perform_addition(const double x1, const double x2)
{
    return x1 + x2;
}
double perform_subtraction(const double x1, const double x2)
{
    return x1 - x2;
}
double perform_multiplication(const double x1, const double x2)
{
    return x1 * x2;
}
double perform_division(const double x1, const double x2)
{
    return x1 / x2; 
}
double perform_exponent(const double x1, const double x2)
{
    return pow(x1, x2);
}

typedef double (*math_operation_function)(const double x1, const double x2);
math_operation_function MathOperations[NUMBER_OF_SUPPORTED_OPERATIONS] = {
                        perform_addition,
                        perform_subtraction,
                        perform_multiplication,
                        perform_division,
                        perform_exponent
};

void perform_math_operation(const double x1, const double x2, const char op)
{
    switch(op)
    {
        case '+':
        {
            cout << x1 << op << x2 << " = " << MathOperations[ADDITION](x1, x2) << endl;
        }
        break;
        case '-':
        {
            cout << x1 << op << x2 << " = " << MathOperations[SUBTRACTION](x1, x2) << endl;
        }
        break;
        case '*':
        {
            cout << x1 << op << x2 << " = " << MathOperations[MULTIPLICATION](x1, x2) << endl;
        }
        break;
        case '/':
        {
            if(x2 == 0.0)
            {
                cout << "Division by zero not possible" << endl;
            }
            else
            {
                cout << x1 << op << x2 << " = " << MathOperations[DIVISION](x1, x2) << endl;
            }
        }
        break;
        case '^':
        {
            if(x1 == 0.0 && x2 == -1.0)
            {
                cout << "Division by zero not possible" << endl;
            }
            else
            {
                cout << x1 << op << x2 << " = " << MathOperations[EXPONENT](x1, x2) << endl;
            }
        }
        break;
        default:
            cout << "Invalid operation requested!" << endl;
    }
}

int main(void)
{
    double x1, x2;
    char op;
    cout << "Enter two numbers: " << endl;
    while(!(cin >> x1 >> x2))
    {
        cout << "Invalid input" << endl;
    }
    cout << "Enter operation to perform (+, -, *, /, ^)";
    while(true)
    {
        string operator_in = "";
        while(!(cin >> operator_in));
        if(operator_in.find_first_not_of("+-*/^") == string::npos && operator_in.length() == 1)
        {
            op = operator_in[0];
            break;
        }
    }
    perform_math_operation(x1, x2, op);
    return 0;
}



#elif (Q3 == 1)
#include <limits>

double max_two(const double x, const double y)
{
    return (x > y) ? x : y;
}
int main(void)
{
    cout << "Please enter two numbers" << endl;
    double x_in, y_in;
    while(!(cin >> x_in >> y_in))
    {
        cout << "Invalid input provided. Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Max of " << x_in << " and " << y_in << " is: " << max_two(x_in, y_in) << endl;
    return 0;
}
#endif
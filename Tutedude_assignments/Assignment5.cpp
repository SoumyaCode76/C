#define Q1                      (1)
#define Q2                      (0)
#define Q3                      (0)

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#if (Q1 == 1)


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
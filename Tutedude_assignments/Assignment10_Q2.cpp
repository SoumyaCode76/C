#include <iostream>
using namespace std;

int main(void)
{
    int a = 0, b = 0;
    while(true)
    {
        try
        {
            cout << "Enter numerator: ";
            while(!(cin >> a));
            cout << "Enter denominator: ";
            while(!(cin >> b));
            {
                if(b == 0)
                {
                    throw 1;    // division by zero
                }
                else
                {
                    cout << "Result of  " << a << "/" << b <<"= " << (a/b) << endl;
                    break;
                }
            }
        }
        catch(int e)
        {
            if(e == 1)
            {
                cout << "Division by zero not possible" << endl;
            }
        }
    }
    return 0;
}
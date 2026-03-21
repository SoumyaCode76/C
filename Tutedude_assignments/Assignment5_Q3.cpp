#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class PlayWithNumber
{
    private:
        int num;
    public:
        int nn;
        PlayWithNumber(int n)
        {
            num = n;
            nn = n;
        }
        unsigned int factorial_number(void)
        {
            unsigned int factorial = 1;
            if(num == 0)
            {
                return 1U;
            }
            for(int i = 1; i <= num; i++)
            {
                factorial *= i;
            }
            return factorial;
        }        
};

int main(void)
{
    string n_in;
    cout << "Enter a non-negative integer: " << endl;
    while(!(cin >> n_in));
    if(n_in.find_first_not_of("1234567890") == string::npos)
    {
        PlayWithNumber Number(stoi(n_in));
        cout << "Factorial of " << Number.nn <<" is: " << Number.factorial_number() << endl;
    }
    else
    {
        cout << "Invalid input! Exiting...\n";
    }
    return 0;
}

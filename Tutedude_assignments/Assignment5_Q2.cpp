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
        int reverse_number(unsigned int base)
        {
            int x = (num >= 0) ? num : ((-1) * (num));
            int reversed = 0;
            while(x != 0)
            {
                reversed = (reversed * base) + (x % base);
                x = x / base;
            }
            if(num < 0)
            {
                return ((-1)*(reversed));
            }
            else
            {
                return reversed;
            }
        }
};

int main(void)
{
    string n_in;
    cout << "Enter an integer: " << endl;
    while(!(cin >> n_in));
    if(n_in.find_first_not_of("1234567890-") == string::npos)
    {
        PlayWithNumber Number(stoi(n_in));
        cout << "Reverse of " << Number.nn <<" is: " << Number.reverse_number(10) << endl;
    }
    else
    {
        cout << "Invalid input! Exiting...\n";
    }
    return 0;
}

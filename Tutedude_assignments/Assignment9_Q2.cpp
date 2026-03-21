#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char*  args[])
{
    if(argc <= 2)
    {
        cout << "Invalid number of arguments passed\n";
        cout << "-c <an alphabet> or  -i <an integer>\n";
        return 0;
    }
    else
    {
        try
        {
            string arg1 = static_cast<string>(args[1]);
            string arg2 = static_cast<string>(args[2]);
            if(arg1 == "-i")
            {
                if(arg2.find_first_not_of("1234567890-") == string::npos)
                {
                    cout << "Inputted integer: " << stoi(arg2) << endl;
                }
                else
                {
                    throw 1;    // Invalid integer entered
                }
            }
            else if(arg1 == "-c")
            {
                if(arg2.length() == 1)
                {
                    int ascii_val = static_cast<int>(arg2[0]);
                    if ( 
                        (ascii_val >= 65 && ascii_val <= 90) ||
                        (ascii_val >= 97 && ascii_val <= 122)
                    )
                    {
                        cout << "Inputted alphabet: " << arg2 << endl;
                    }
                    else
                    {
                        throw 2;    // Invalid character entered
                    }
                }
            }
            else
            {
                cout << "Invalid option passed" << endl;
            }
        }
        catch(int e)
        {
            if(e == 1)
            {
                cout << "Invalid integer entered" << endl;
            }
            else if(e == 2)
            {
                cout << "Invalid alphabet entered" << endl;
            }
        }
    }
    return 0;
}
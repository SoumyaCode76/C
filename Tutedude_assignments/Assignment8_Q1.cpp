#include <iostream>
using namespace std;

class Base
{
    private:
        int b;
    public:
        Base(int x) : b(x)
        {
            cout << "From base class: " << b << endl;
        }
        void set_value(int v)
        {
            b = v;
        }
        int get_value(void)
        {
            return b;
        }
        ~Base()
        {
            cout << "Base class object destroyed" << endl;
        }
};

int main()
{
    {
        Base B(5);
        B.get_value();
    }
    return 0;
}
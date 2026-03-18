#include <iostream>
using namespace std;

class Base
{
    private:
        int b;
    public:
        Base(int x)
        {
            b = x;
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
};

class Derived : public Base
{
    private:
        int d;
    public:
        Derived(int y) : Base(y * 2)
        {
            d = y;
            cout << "From derived class: " << y << endl;
        }
        void set_value(int v)
        {
            d = v;
        }
        int get_value(void)
        {
            return d;
        }
};

int main()
{
    Base* bp = new Derived(10);
    bp->set_value(30);
    cout << "Value of bp->b: " << bp->get_value() << endl;    
}
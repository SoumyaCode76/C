#include <iostream>
using namespace std;

class Base
{
    private:
        int data1, data2;    
    public:
        int d1, d2;
        Base(int a = 0, int b = 0) : data1(a), data2(b)
        {
            d1 = data1;
            d2 = data2;
        }
};

class Derived : public Base
{
    public:
        Derived()
        {

        }
        Derived(int x1, int x2) : Base(x1, x2)
        {

        }
        void show()
        {
            cout << "data1 = " << d1 << ";data2 = " << d2 << endl;
        }
};

int main(void)
{
    Derived d;
    d.show();
    Derived d2(5, 10);
    d2.show();
    return 0;
}
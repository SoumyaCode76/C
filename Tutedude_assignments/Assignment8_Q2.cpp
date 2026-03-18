#include <iostream>
using namespace std;

typedef enum
{
        RECTANGLE = 1U,
        TRIANGLE,
        EXIT
}tChoice;

class Shape
{
    public:
        virtual double calculate_area(void) = 0;
};

class Rectangle : public Shape
{
    private:
        double length;
        double breadth;
    public:
        Rectangle(double l, double b) : length(l), breadth(b)
        {
            cout << "Rectangle of length " << length << " and breadth " << breadth << " created\n";
        }
        double calculate_area(void)
        {
            return (length * breadth);
        }
        ~Rectangle(void)
        {
            cout << "Rectangle destroyed" << endl;
        } 
};

class Triangle : public Shape
{
    private:
        double base;
        double height;
    public:
        Triangle(double b, double h) : base(b), height(h)
        {
            cout << "Triangle of base " << base << " and height " << height << " created\n";            
        }
        double calculate_area(void)
        {
            return (0.5 * base * height);
        }
        ~Triangle(void)
        {
            cout << "Triangle destroyed" << endl;
        }
};

int main()
{
    string choice;
    tChoice ch;
    while(true)
    {
        cout << "=========================================\n";
        cout << "1. Calculate area of rectangle\n";
        cout << "2. Calculate area of triangle\n";
        cout << "3. exit\n";
        cout << "=========================================\n";
        do
        {
            cin >> choice;
        }while(choice.empty());
        if(choice.find_first_not_of("123") == string::npos)
        {
            ch = static_cast<tChoice>(stoi(choice));
            switch(ch)
            {
                case RECTANGLE:
                {
                    double l = 0.0, b = 0.0;
                    cout << "Enter the length and breadth of the rectangle\n";
                    while(!(cin >> l >> b ));
                    Rectangle R(l, b);
                    cout << "Area of the rectangle: " << R.calculate_area() << endl;
                }
                break;
                case TRIANGLE:
                {
                    double b = 0.0, h = 0.0;
                    cout << "Enter the base and height of the triangle\n";
                    while(!(cin >> b >> h ));
                    Triangle T(b, h);
                    cout << "Area of the triangle: " << T.calculate_area() << endl;                    
                }
                break;
                case EXIT:
                {
                    cout << "Goodbye!\n";
                    exit(EXIT_SUCCESS);
                }
                break;
                default:
                    cout << "Incorrect option selected\n";
             }
        }
        else
        {
            cout << "Invalid choice given. Please try again!\n";
            continue;
        }
    }
    return 0;
}
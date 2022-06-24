#include <iostream>
using namespace std;

class Shape
{
public:
    virtual ~Shape()
    {
        cout << "A Shape has been destroyed" << endl;
    };
};

class Rectangle : public Shape
{
public:
    virtual ~Rectangle()
    {
        cout << "A Rectangle has been destroyed." << endl;
    };
};

class Square : public Rectangle
{
public:
    ~Square()
    {
        cout << "A Square has been destroyed." << endl;
    };
};

int main()
{
    Shape *shape1 = new Square();
    delete shape1;
    system("pause");
    return 0;
}
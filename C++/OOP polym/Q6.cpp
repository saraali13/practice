#include <iostream>
using namespace std;

// Interface: a class having only pure virtual functions
class Shape 
{
public:
    // Pure virtual function (no implementation)
    virtual void draw() = 0;
    virtual void display() = 0;
};

// Concrete Classes implementing Shape interface
class Circle : public Shape 
{
public:
    void draw()
	{
        cout << "Drawing Circle\n";
    }
    void display()
    {
    	cout<<"this is a circle\n";
	}
};

class Square : public Shape 
{
public:
    void draw() override 
	{
        cout << "Drawing Square\n";
    }
        void display()
    {
    	cout<<"this is a circle\n";
	}
};

int main() {
    Circle circle;
    Square square;

    // Using interface
    Shape* shape1 = &circle;
    Shape* shape2 = &square;


    shape1->draw(); // circle class functions
    shape1->draw();
    
    shape2->draw(); // square clqass funtions
    shape2->draw();

    return 0;
}

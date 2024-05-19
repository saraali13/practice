#include <iostream>
using namespace std;

class Point 
{
private:
    int x, y;

public:
    // Default constructor
    Point() : x(0), y(0) 
    {}

    // Parameterized constructor
    Point(int x, int y) : x(x), y(y) 
    {}

    // Friend function for overloading the insertion operator (<<)
    friend ostream& operator<<(ostream& os, const Point p);

    // Friend function for overloading the extraction operator (>>)
    friend istream& operator>>(istream& is, Point& p);
};

// Overload the << operator
ostream& operator<<(ostream& os, const Point p) 
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// Overload the >> operator
istream& operator>>(istream& is, Point & p) 
{
    cout << "Enter x coordinate: ";
    is >> p.x;
    cout << "Enter y coordinate: ";
    is >> p.y;
    return is;
}

int main() 
{
    Point p1, p2;

    cout << "Enter coordinates for point p1:\n";
    cin >> p1;
    cout << "You entered p1: " << p1 << endl;

    cout << "Enter coordinates for point p2:\n";
    cin >> p2;
    cout << "You entered p2: " << p2 << endl;

    return 0;
}

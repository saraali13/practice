#include <iostream>
using namespace std;

class Point {

private:
    int x, y;

public:
    Point(int x , int y ) : x(x), y(y) {}

    // Overload the assignment operator
    Point operator=(Point other) 
    {    Point p(x,y);
        if (p.x == other.x && p.y ==other.y) 
        {
            return p; // Handle self-assignment
        }
        p.x = other.x;
        p.y = other.y;
        return p;
    }

    // Overload the equality operator
    bool operator==( Point other)
    {
        Point p(x,y);
        return (p.x == other.x && p.y == other.y);
    }

    // Overload the inequality operator
    bool operator!=(Point other) 
    { 
        Point p(x,y);
        return !(p == other);
    }

    // Overload the less than operator
    bool operator<( Point other) 
    {
        Point p(x,y);
        return ((p.x < other.x && p.y < other.y));
    }

    // Overload the greater than operator
    bool operator>(Point other) 
    {
        Point p(x,y);
        return ((p.x > other.x && p.y > other.y));
    }

    // Overload the less than or equal to operator
    bool operator<=(Point other)  
    {
        Point p(x,y);
        return !(other < p);
    }

    // Overload the greater than or equal to operator
    bool operator>=( Point other) 
    {
        Point p(x,y);
        return !( p < other);
    }

    // Function to print point coordinates
    void print()
    {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3, 4), p2(5, 6), p3(3, 4);

    // Test assignment operator
    Point p4 = p1;
    cout << "p4 = ";
    p4.print();
    cout << endl;

    // Test equality and inequality operators
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 == p3: " << (p1 == p3) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;

    // Test comparison operators
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;
    cout << "p1 <= p3: " << (p1 <= p3) << endl;
    cout << "p1 >= p3: " << (p1 >= p3) << endl;

    return 0;
}

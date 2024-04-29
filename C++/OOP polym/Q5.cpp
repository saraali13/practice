#include <iostream>
using namespace std;

// using simple pure virtual functions 

class base // base class
{
public:
    virtual int sum(int a, int b) = 0; // pure virtual function
};

class derived1 : public base // class derived from base class
{
public:
    int sum(int a, int b)// override the pure virtual function
    {
        return a + b;
    }
};

class derived2 : public base // class derived from base class
{
public:
    int sum(int a, int b)// override the pure virtual function
    {
        a += a;
        return a + b;
    }
};

int main()
{
    derived1 D1;
    derived2 D2;

    base *Bptr = &D1; // base pointer to derived class 1 obj
    int result1 = Bptr->sum(2, 4); // calling derived1's sum() function
    cout << "Result from derived1: " << result1 << endl;

    Bptr = &D2; // base pointer to derived class 2 obj
    int result2 = Bptr->sum(2, 4); // calling derived2's sum() function
    cout << "Result from derived2: " << result2 << endl;

    return 0;
}

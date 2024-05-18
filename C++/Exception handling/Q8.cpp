#include <iostream>
#include <exception>
using namespace std;

int main()
{
    int a, b, n;
    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

    try
    {
        if (b == 0) 
        {
            throw runtime_error("cannot be divided by 0");//if we'll not write the type of error then it will not give desired output 
        } 
        else 
        {
            n = a / b;
        }
    } 
    catch (const exception &e) 
        {
        cout << "Exception: " << e.what() << endl;
        return 1;  // Exit the program with an error code else it will show some garbage value after the exception's output
        }

    cout << "Result: " << n << endl;
    return 0;
}

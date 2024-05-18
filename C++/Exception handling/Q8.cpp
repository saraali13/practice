#include <iostream>
#include <exception>
using namespace std;

int main()
{
    int a, b, n;
    cout << "Enter two integers (a and b): ";
    cin >> a >> b;

    try {
        if (b == 0) {
            throw runtime_error("cannot be divided by 0");
        } else {
            n = a / b;
        }
    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
        return 1;  // Exit the program with an error code
    }

    cout << "Result: " << n << endl;
    return 0;
}

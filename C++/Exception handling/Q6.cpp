#include <iostream>
using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter numerator: ";
        cin >> a;
        cout << "Enter denominator: ";
        cin >> b;

        if (b == 0) {
            throw "Cannot divide by zero";
        }

        int result = a / b;
        cout << "Result = " << result << endl;
    } 
    catch (const char *str) {
        cout << "Exception caught: "<<str;
    }

    return 0;
}

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int a, b;

    try {
        cout << "Enter numerator: ";
        cin >> a;
        cout << "Enter denominator: ";
        cin >> b;

        if (b == 0) {
            throw runtime_error("Cannot divide by zero");
        }

        int result = a / b;
        cout << "Result = " << result << endl;
    } 
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}

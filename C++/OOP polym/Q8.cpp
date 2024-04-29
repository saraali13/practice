#include <iostream>
using namespace std;

// Template function: generic programming ==algo can be used for all data types, no need to write different code for different data types
template<typename T>
T maxx(T a, T b) {
    return (a > b) ? a : b; // if a > b then return a, else return b
}

int main() {
    // Using the maximum function with integers
    int intMax = maxx(5, 10); // using the max function from the global namespace
    cout << "Maximum of 5 and 10 is: " << intMax << endl;

    // Using the maximum function with floating-point numbers
    double doubleMax = maxx(3.5, 6.8); // using the max function from the global namespace
    cout << "Maximum of 3.5 and 6.8 is: " << doubleMax << endl;

    // Using the maximum function with characters
    char charMax = maxx('a', 'z'); // using the max function from the global namespace
    cout << "Maximum of 'a' and 'z' is: " << charMax << endl;

    return 0;
}

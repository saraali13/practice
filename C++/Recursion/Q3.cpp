#include <iostream>
using namespace std;

// Recursive function to find the factorial of a number
int factorial(int n) {
    // Base case: if n is 0, return 1
    if (n == 0) 
        return 1;

    // Recursive case: multiply n with factorial of (n - 1)
    return n * factorial(n - 1);
}

int main() {
    int n;

    // Input a number
    cout << "Enter a number: ";
    cin >> n;

    // Calculate factorial using recursion
    int result = factorial(n);

    // Output the result
    cout << "Factorial of " << n << " is " << result << endl;

    return 0;
}

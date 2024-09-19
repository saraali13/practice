#include <iostream>
using namespace std;

// Recursive function to find the n-th Fibonacci number
int fibonacci(int n) {
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive case: sum of previous two Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    // Input the position in the Fibonacci sequence
    cout << "Enter a position: ";
    cin >> n;

    // Calculate the Fibonacci number using recursion
    int result = fibonacci(n);

    // Output the result
    cout << "Fibonacci number at position " << n << " is " << result << endl;

    return 0;
}

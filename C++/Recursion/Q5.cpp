#include <iostream>
using namespace std;

// Recursive function to find x^n
int power(int x, int n) {
    // Base case: if exponent is 0, return 1
    if (n == 0)
        return 1;

    // Recursive case: multiply x with power(x, n - 1)
    return x * power(x, n - 1);
}

int main() {
    int x, n;

    // Input the base and exponent
    cout << "Enter base and exponent: ";
    cin >> x >> n;

    // Calculate the power using recursion
    int result = power(x, n);

    // Output the result
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}

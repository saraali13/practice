#include <iostream>
using namespace std;

// Recursive function to reverse a string
void reverseString(string &str, int start, int end) {
    // Base case: when the start index meets or crosses the end index
    if (start >= end)
        return;

    // Swap the characters at start and end
    swap(str[start], str[end]);

    // Recursive call with narrowed range
    reverseString(str, start + 1, end - 1);
}

int main() {
    string str;

    // Input a string
    cout << "Enter a string: ";
    cin >> str;

    // Reverse the string using recursion
    reverseString(str, 0, str.length() - 1);

    // Output the reversed string
    cout << "Reversed string: " << str << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Recursive function to check if a string is a palindrome
bool isPalindrome(const string &str, int start, int end) {
    // Base case: if the string has one or no characters left
    if (start >= end)
        return true;

    // Check if characters at start and end are the same
    if (str[start] != str[end])
        return false;

    // Recursive call with narrowed range
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    string str;

    // Input a string
    cout << "Enter a string: ";
    cin >> str;

    // Check if the string is a palindrome using recursion
    bool result = isPalindrome(str, 0, str.length() - 1);

    // Output the result
    if (result)
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}

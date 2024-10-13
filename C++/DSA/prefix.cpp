#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to reverse a string
string reverseString(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// Function to convert infix to prefix
string infixToPrefix(const string& infix) {
    stack<char> operators;
    string prefix;

    // Reverse the infix expression
    string reversedInfix = reverseString(infix);

    for (char ch : reversedInfix) {
        // If the character is an operand, add it to the output
        if (isalnum(ch)) {
            prefix += ch;
        }
        // If the character is ')', push it to the stack
        else if (ch == ')') {
            operators.push(ch);
        }
        // If the character is '(', pop from the stack to the output until ')' is found
        else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the ')'
        }
        // If the character is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) > precedence(ch)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    // Reverse the prefix expression to get the final result
    return reverseString(prefix);
}

int main() 
{
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}

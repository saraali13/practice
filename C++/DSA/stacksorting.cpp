#include <iostream>
#include <stack>
using namespace std;

// Function to sort a stack using another stack
void sortStack(stack<int>& input) {
    stack<int> tempStack;

    while (!input.empty()) {
        int tmp = input.top();
        input.pop();

        // Move elements from tempStack back to input if they are greater than tmp
        while (!tempStack.empty() && tempStack.top() > tmp) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        // Push tmp onto tempStack in sorted position
        tempStack.push(tmp);
    }

    // Move back all elements from tempStack to input
    while (!tempStack.empty()) {
        input.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> myStack;
    myStack.push(34);
    myStack.push(3);
    myStack.push(31);
    myStack.push(98);
    myStack.push(92);
    myStack.push(23);

    cout << "Original Stack: ";
    stack<int> temp = myStack;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(myStack);

    cout << "Sorted Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}

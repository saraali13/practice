#include <iostream>
#include <stack>
using namespace std;

// Function to partition the stack
int partition(stack<int>& s, int l, int h, int pivot) {
    stack<int> tempStack;
    int smallerCount = 0;

    while (!s.empty()) {
        int val = s.top();
        s.pop();
        if (val < pivot)
            smallerCount++;
        tempStack.push(val);
    }

    // Transfer elements back in partitioned order
    int i = 0;
    while (!tempStack.empty()) {
        int val = tempStack.top();
        tempStack.pop();
        if (val < pivot)
            s.push(val);
        if (val >= pivot)
            s.push(val);
    }
    return smallerCount;
}

// Function to perform quick sort on a stack
void quickSortStack(stack<int>& s, int l, int h) {
    if (l >= h)
        return;

    // Partition
    int pivot = s.top();
    int pi = partition(s, l, h, pivot);

    // Recursively sort the sub-stacks
    quickSortStack(s, l, pi - 1);
    quickSortStack(s, pi + 1, h);
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

    quickSortStack(myStack, 0, myStack.size() - 1);

    cout << "Sorted Stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}

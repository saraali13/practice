#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& s, int element) {
    if (s.empty() || element > s.top()) {
        s.push(element);
    } else {
        int top = s.top();
        s.pop();
        sortedInsert(s, element);
        s.push(top);
    }
}

void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int top = s.top();
        s.pop();
        sortStack(s);
        sortedInsert(s, top);
    }
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(14);
    s.push 7);

    sortStack(s);

    cout << "Sorted Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

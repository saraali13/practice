#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    // Pop elements
    s.pop();
    cout << "After popping, top element: " << s.top() << endl;

    return 0;
}

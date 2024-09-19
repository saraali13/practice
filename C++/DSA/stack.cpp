#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    static const int MAX = 1000;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    bool push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack overflow. Cannot push " << x << endl;
            return false;
        }
        arr[++top] = x;
        cout << x << " pushed onto the stack." << endl;
        return true;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack underflow. Nothing to pop." << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " popped from the stack." << endl;

    cout << "Top element is: " << s.peek() << endl;

    if (s.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}

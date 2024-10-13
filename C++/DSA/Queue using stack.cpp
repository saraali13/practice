#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

public:
    void enqueue(int value) {
        s1.push(value);
    }

    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty\n";
                return;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Dequeued: " << s2.top() << "\n";
        s2.pop();
    }

    void display() {
        if (!s2.empty()) {
            stack<int> temp = s2;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
        }
        stack<int> temp = s1;
        stack<int> rev;
        while (!temp.empty()) {
            rev.push(temp.top());
            temp.pop();
        }
        while (!rev.empty()) {
            cout << rev.top() << " ";
            rev.pop();
        }
        cout << "\n";
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();  // Output: 1 2 3
    q.dequeue();  // Output: Dequeued: 1
    q.display();  // Output: 2 3
    return 0;
}

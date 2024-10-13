#include <iostream>
#include <queue>
using namespace std;

// Function to reverse the queue using recursion
void reverseQueue(queue<int>& q) {
    // Base case: if the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Remove the front element
    int front = q.front();
    q.pop();

    // Recursively reverse the remaining queue
    reverseQueue(q);

    // Add the removed element back to the end of the queue
    q.push(front);
}

int main() {
    queue<int> q;

    // Adding elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    queue<int> temp = q; // Temporary queue for displaying the original queue
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue
    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

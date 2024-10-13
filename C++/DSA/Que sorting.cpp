#include <iostream>
#include <queue>
using namespace std;

// Function to insert an element into the queue in sorted order
void insertInSortedOrder(queue<int>& q, int element) {
    // Base case: If the queue is empty or element is greater than the front element
    if (q.empty() || element >= q.front()) {
        q.push(element);
        return;
    }

    // Remove the front element
    int temp = q.front();
    q.pop();

    // Recursive call
    insertInSortedOrder(q, element);

    // Push the removed element back
    q.push(temp);
}

// Recursive function to sort the queue
void sortQueue(queue<int>& q) {
    if (q.empty())
        return;

    // Remove the front element
    int temp = q.front();
    q.pop();

    // Sort the remaining queue
    sortQueue(q);

    // Insert the front element in sorted order
    insertInSortedOrder(q, temp);
}

int main() {
    queue<int> q;
    q.push(34);
    q.push(3);
    q.push(31);
    q.push(98);
    q.push(92);
    q.push(23);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

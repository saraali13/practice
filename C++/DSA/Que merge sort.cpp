#include <iostream>
#include <queue>
using namespace std;

void merge(queue<int>& left, queue<int>& right, queue<int>& q) {
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            q.push(left.front());
            left.pop();
        } else {
            q.push(right.front());
            right.pop();
        }
    }
    while (!left.empty()) {
        q.push(left.front());
        left.pop();
    }
    while (!right.empty()) {
        q.push(right.front());
        right.pop();
    }
}

void mergeSortQueue(queue<int>& q) {
    if (q.size() <= 1)
        return;

    int mid = q.size() / 2;

    queue<int> left;
    queue<int> right;

    for (int i = 0; i < mid; i++) {
        left.push(q.front());
        q.pop();
    }

    while (!q.empty()) {
        right.push(q.front());
        q.pop();
    }

    mergeSortQueue(left);
    mergeSortQueue(right);

    merge(left, right, q);
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

    mergeSortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

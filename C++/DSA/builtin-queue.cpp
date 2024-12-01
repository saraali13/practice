#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << ", Back: " << q.back() << endl;

    // Remove elements
    q.pop();
    cout << "After popping, front: " << q.front() << endl;

    return 0;
}

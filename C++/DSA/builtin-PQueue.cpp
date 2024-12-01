#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    priority_queue<int,greater<int>> minHeap;
    // Insert elements
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);

    cout << "Top element (max): " << maxHeap.top() << endl;

    maxHeap.pop();
    cout << "After popping, top element (max): " << maxHeap.top() << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // Max-Heap for priority queue

    // Restore heap property going up
    void heapifyUp(int index) {
        if (index == 0) return; // Base case: root node

        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent); // Recursively heapify the parent
        }
    }

    // Restore heap property going down
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // Check if the left child is larger
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check if the right child is larger
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If the largest is not the current node, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert a new element into the priority queue
    void insert(int value) {
        heap.push_back(value);       // Add the new value to the end
        heapifyUp(heap.size() - 1); // Restore the heap property
    }

    // Get the maximum element (highest priority)
    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1; // Indicate empty queue
        }
        return heap[0];
    }

    // Remove the maximum element (highest priority)
    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty! Cannot pop." << endl;
            return;
        }
        heap[0] = heap.back(); // Replace root with the last element
        heap.pop_back();       // Remove the last element
        heapifyDown(0);        // Restore the heap property
    }

    // Get the size of the priority queue
    int size() {
        return heap.size();
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Print all elements (for debugging purposes)
    void printQueue() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Insert elements
    pq.insert(10);
    pq.insert(20);
    pq.insert(15);
    pq.insert(30);
    pq.insert(25);

    cout << "Priority Queue after insertions: ";
    pq.printQueue();

    // Get the top element
    cout << "Top element (max priority): " << pq.top() << endl;

    // Remove the top element
    pq.pop();
    cout << "Priority Queue after popping the top element: ";
    pq.printQueue();

    // Check size and if empty
    cout << "Size of priority queue: " << pq.size() << endl;
    cout << "Is priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;

    // Pop all elements
    while (!pq.isEmpty()) {
        cout << "Removing top element: " << pq.top() << endl;
        pq.pop();
    }

    // Try popping from an empty queue
    pq.pop();

    return 0;
}

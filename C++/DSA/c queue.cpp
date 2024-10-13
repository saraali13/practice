#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;      // Array to hold the queue elements
    int front;     // Front pointer
    int rear;      // Rear pointer
    int capacity;  // Maximum size of the queue
    int count;     // Current size of the queue

public:
    CircularQueue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Function to add an item to the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Wrap around
        arr[rear] = item;
        count++;
        cout << "Enqueued: " << item << endl;
    }

    // Function to remove an item from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicating failure
        }
        int item = arr[front];
        front = (front + 1) % capacity; // Wrap around
        count--;
        cout << "Dequeued: " << item << endl;
        return item;
    }

    // Function to get the front item
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front item." << endl;
            return -1; // Indicating failure
        }
        return arr[front];
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == capacity;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to get the current size of the queue
    int size() {
        return count;
    }
};

int main() {
    CircularQueue queue(5); // Create a circular queue of size 5

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60); // Attempting to enqueue when full

    cout << "Front item is: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front item is: " << queue.peek() << endl;

    queue.enqueue(60);
    queue.enqueue(70); // Adding more items

    while (!queue.isEmpty()) {
        queue.dequeue(); // Dequeue all items
    }

    return 0;
}

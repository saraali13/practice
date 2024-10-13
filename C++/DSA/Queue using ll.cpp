#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front node
    Node* rear;  // Pointer to the rear node

public:
    Queue() : front(NULL), rear(NULL) {}

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == NULL) { // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode; // Link the new node at the end
            rear = newNode;        // Update rear to new node
        }
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicating failure
        }
        int item = front->data; // Get the data from front
        Node* temp = front;     // Temporary node to delete
        front = front->next;    // Move front to next node
        if (front == NULL)      // If the queue becomes empty
            rear = NULL;        // Set rear to NULL
        delete temp;           // Free memory
        cout << "Dequeued: " << item << endl;
        return item;
    }

    // Function to get the front item
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front item." << endl;
            return -1; // Indicating failure
        }
        return front->data; // Return front data
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL; // Check if front is NULL
    }

    // Function to get the current size of the queue
    int size() {
        int count = 0;
        Node* current = front; // Start from front
        while (current != NULL) { // Traverse the list
            count++; // Increment count for each node
            current = current->next; // Move to the next node
        }
        return count; // Return the size
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue(); // Dequeue all elements
        }
    }
};

int main() {
    Queue queue; // Create a queue

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Front item is: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue();

    cout << "Front item is: " << queue.peek() << endl;

    queue.enqueue(50);
    queue.enqueue(60);

    while (!queue.isEmpty()) {
        queue.dequeue(); // Dequeue all items
    }

    return 0;
}

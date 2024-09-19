#include <iostream>
using namespace std;

// Structure for a single node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to calculate the size of a linked list
int getSize(Node* head) {
    int count = 0;
    Node* current = head;

    // Traverse the list and count the nodes
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Helper function to insert a node at the end of a linked list
void insertAtEnd(Node*& head, int value) {
    if (head == nullptr) {
        head = new Node(value);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(value);
    }
}

// Helper function to display a linked list
void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
}

int main() {
    Node* head = nullptr;

    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Display the linked list
    cout << "Linked List: ";
    displayList(head);

    // Calculate the size of the linked list
    int size = getSize(head);

    // Print the size
    cout << "Size of the linked list: " << size << endl;

    return 0;
}

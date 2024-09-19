#include <iostream>
using namespace std;

// Define the structure of a node in a singly linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to insert a node at the end of the list
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

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

// Function to swap two nodes given their previous nodes
void swapNodes(Node*& head, Node* prevX, Node* currX, Node* prevY, Node* currY) {
    // If one of the nodes to be swapped is head
    if (prevX != nullptr) {
        prevX->next = currY;
    } else {
        head = currY;
    }

    if (prevY != nullptr) {
        prevY->next = currX;
    } else {
        head = currX;
    }

    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

// Function to perform Bubble Sort
void bubbleSort(Node*& head) {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;
        Node* prev1 = nullptr;
        Node* prev2 = nullptr;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap nodes, not just data
                swapNodes(head, prev1, ptr1, ptr1, ptr1->next);
                swapped = true;

                // After swapping, move prev1 to ptr1 which is now next
                prev1 = ptr1->next;
                ptr1 = ptr1->next;
            } else {
                prev1 = ptr1;
                ptr1 = ptr1->next;
            }
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    // Insert nodes into the linked list
    insertAtEnd(head, 64);
    insertAtEnd(head, 34);
    insertAtEnd(head, 25);
    insertAtEnd(head, 12);
    insertAtEnd(head, 22);
    insertAtEnd(head, 11);
    insertAtEnd(head, 90);

    cout << "Original List: ";
    displayList(head);

    // Sort the list using Bubble Sort
    bubbleSort(head);

    cout << "Sorted List: ";
    displayList(head);

    return 0;
}

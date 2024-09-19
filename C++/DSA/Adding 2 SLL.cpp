#include <iostream>
using namespace std;

// Structure for a single node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to add two numbers represented by linked lists (without carry)
Node* addTwoListsWithoutCarry(Node* l1, Node* l2) {
    Node* dummyHead = new Node(0);  // Dummy node to simplify result list creation
    Node* current = dummyHead;      // Pointer to traverse and build the result list

    while (l1 != nullptr || l2 != nullptr) {
        int sum = 0;

        // Add the current values from both lists (if available)
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        // Add the sum to the result linked list
        current->next = new Node(sum);
        current = current->next;
    }

    // The result linked list starts after the dummy node
    return dummyHead->next;
}

// Helper function to display a linked list
void displayList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "null\n";
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

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    // Creating first number: 342 (reversed order: 2 -> 4 -> 3)
    insertAtEnd(l1, 2);
    insertAtEnd(l1, 4);
    insertAtEnd(l1, 3);

    // Creating second number: 465 (reversed order: 5 -> 6 -> 4)
    insertAtEnd(l2, 5);
    insertAtEnd(l2, 6);
    insertAtEnd(l2, 4);

    cout << "First List: ";
    displayList(l1);
    
    cout << "Second List: ";
    displayList(l2);

    // Adding the two linked lists without carry
    Node* result = addTwoListsWithoutCarry(l1, l2);

    // Display the result
    cout << "Result List (Sum without Carry): ";
    displayList(result);

    return 0;
}

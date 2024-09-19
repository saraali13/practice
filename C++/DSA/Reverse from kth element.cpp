#include <iostream>
using namespace std;

// Structure for a single node in the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to reverse the list before the k-th element
Node* reverseBeforeKth(Node* head, int k)
{//after m bhi same hi tareeky se hoga bss curr ko k tk le k jana hota for loop use krk phly
    
    if (head == nullptr || k <= 1) return head;  // If k <= 1, no reversal is needed

    Node* current = head;
    Node* prev = nullptr;
    
    // Traverse to the k-th node and reverse the first (k-1) nodes
    Node* kthNode = nullptr;
    Node* nextNode = nullptr;
    int count = 1;

    while (current != nullptr && count < k) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        count++;
    }

    // Now 'prev' is the new head of the reversed part
    // 'current' is the k-th node, which should remain in place

    // Reconnect the reversed part with the rest of the list
    if (head != nullptr) {
        head->next = current;
    }

    return prev;  // The new head is the last node we reversed (which was at (k-1))
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
    Node* head = nullptr;

    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    cout << "Original List: ";
    displayList(head);

    int k = 4;  // Reverse everything before the 4-th element
    head = reverseBeforeKth(head, k);

    cout << "List after reversing before " << k << "-th element: ";
    displayList(head);

    return 0;
}

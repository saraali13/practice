#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to split the linked list into two halves
void splitList(Node* head, Node** left, Node** right) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = head;
    *right = slow->next;
    slow->next = nullptr;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

// Merge Sort function
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    if (head == nullptr || head->next == nullptr)
        return;

    Node* left;
    Node* right;

    splitList(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = merge(left, right);
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(12);
    head->next = new Node(11);
    head->next->next = new Node(13);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

    cout << "Original List: ";
    printList(head);

    mergeSort(&head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

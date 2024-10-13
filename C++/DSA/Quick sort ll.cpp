#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to swap the data of two nodes
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Partition function for Quick Sort on linked list
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data < pivot) {
            swap(i, j);
            i = i->next;
        }
    }
    swap(i, high);
    return i;
}

// Quick Sort function
void quickSort(Node* low, Node* high) {
    if (low != high && high != nullptr && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p);
        quickSort(p->next, high);
    }
}

// Function to get the tail node
Node* getTail(Node* head) {
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;
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
    Node* head = new Node(10);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    Node* tail = getTail(head);
    quickSort(head, tail);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert at the front
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete from head
    void deleteFromHead() {
        if (head == nullptr) return;
        
        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }

    // Delete from tail
    void deleteFromTail() {
        if (head == nullptr) return;

        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    // Display the list
    void display() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD\n";
    }
};

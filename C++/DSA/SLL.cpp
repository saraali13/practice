#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Insert at the front
    void insertAtFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert after a given node
    void insertAfter(Node* prevNode, int value) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null\n";
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete from head
    void deleteFromHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete node with a specific value (first occurrence)
    void deleteNode(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            deleteFromHead();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Delete from tail
    void deleteFromTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete the entire list
    void deleteList() {
        while (head != nullptr) {
            deleteFromHead();
        }
    }

    // Copy constructor
    SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr) {
        if (other.head == nullptr) return;
        Node* temp = other.head;
        while (temp != nullptr) {
            insertAtEnd(temp->data);
            temp = temp->next;
        }
    }

    // Destructor
    ~SinglyLinkedList() {
        deleteList();
    }

    // Search for a value in the list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }
};

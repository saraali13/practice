#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;

    DNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Insert at the front
    void insertAtFront(int value) {
        DNode* newNode = new DNode(value);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Insert after a given node
    void insertAfter(DNode* prevNode, int value) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be null\n";
            return;
        }
        DNode* newNode = new DNode(value);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != nullptr) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        DNode* newNode = new DNode(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete from head
    void deleteFromHead() {
        if (head == nullptr) return;
        DNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    // Delete node with a specific value (first occurrence)
    void deleteNode(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            deleteFromHead();
            return;
        }

        DNode* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found\n";
            return;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    // Delete from tail
    void deleteFromTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
    }

    // Delete the entire list
    void deleteList() {
        while (head != nullptr) {
            deleteFromHead();
        }
    }

    // Copy constructor
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr) {
        if (other.head == nullptr) return;
        DNode* temp = other.head;
        while (temp != nullptr) {
            insertAtEnd(temp->data);
            temp = temp->next;
        }
    }

    // Destructor
    ~DoublyLinkedList() {
        deleteList();
    }

    // Search for a value in the list
    bool search(int value) {
        DNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverse() {
        DNode* temp = nullptr;
        DNode* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Display the list
    void display() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "null\n";
    }
};

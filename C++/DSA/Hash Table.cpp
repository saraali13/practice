#include <iostream>
#include <vector>
using namespace std;

#define SIZE 20 // Size of the hash table

// Structure to represent an item in the hash table
struct DataItem {
    int key;  // Key of the item
    int data; // Data stored in the item
};

// Global variables
vector<DataItem*> hashArray(SIZE, nullptr); // Hash table as a vector
DataItem* dummyItem = new DataItem{-1, -1}; // Dummy item for marking deleted slots

// Hash function: returns the index based on the key
int hashCode(int key) {
    return key % SIZE;
}

// Function to insert an item into the hash table
void insert(int key, int data) {
    DataItem* item = new DataItem{key, data}; // Create a new item
    int hashIndex = hashCode(key);           // Compute the hash index

    // Handle collisions using linear probing
    while (hashArray[hashIndex] != nullptr && hashArray[hashIndex]->key != -1) {
        hashIndex = (hashIndex + 1) % SIZE; // Move to the next index
    }

    hashArray[hashIndex] = item; // Insert the item
}

// Function to search for an item by its key
DataItem* search(int key) {
    int hashIndex = hashCode(key);

    // Search for the key using linear probing
    while (hashArray[hashIndex] != nullptr) {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex]; // Return the item if key matches
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }

    return nullptr; // Key not found
}

// Function to delete an item by its key
void deleteItem(int key) {
    int hashIndex = hashCode(key);

    // Search for the key using linear probing
    while (hashArray[hashIndex] != nullptr) {
        if (hashArray[hashIndex]->key == key) {
            delete hashArray[hashIndex];   // Free memory of the item
            hashArray[hashIndex] = dummyItem; // Mark slot as deleted
            return;
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }

    cout << "\nKey " << key << " not found for deletion.";
}

// Function to display the hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != nullptr && hashArray[i]->key != -1) {
            cout << "(" << hashArray[i]->key << ", " << hashArray[i]->data << ") ";
        } else {
            cout << "~~ "; // Indicate empty slots
        }
    }
    cout << endl;
}

// Main function to test the hash table
int main() {
    // Insert items
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    cout << "Contents of Hash Table: ";
    display();

    // Search for an element
    int keyToSearch = 37;
    cout << "\nSearching for key: " << keyToSearch << endl;
    DataItem* item = search(keyToSearch);
    if (item != nullptr) {
        cout << "Element found: (" << item->key << ", " << item->data << ")\n";
    } else {
        cout << "Element not found.\n";
    }

    // Delete an element
    cout << "Deleting key: " << keyToSearch << endl;
    deleteItem(keyToSearch);
    cout << "Contents of Hash Table after deletion: ";
    display();

    return 0;
}

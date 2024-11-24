#include <iostream>
#include <vector>
using namespace std;

// Initial size of the hash table
#define INITIAL_SIZE 10

// Structure to represent an item in the hash table
struct DataItem {
    int key;  // Key of the item
    int data; // Data stored in the item
};

// Class to manage the hash table
class HashTable {
private:
    vector<DataItem*> hashArray; // Hash table as a vector
    DataItem* dummyItem;         // Dummy item for marking deleted slots
    int tableSize;               // Current size of the hash table
    int currentSize;             // Current number of elements

    // Hash function: returns the index based on the key
    int hashCode(int key) {
        return key % tableSize;
    }

    // Function to check the load factor and rehash if necessary
    void checkLoadFactor() {
        double loadFactor = (double)currentSize / tableSize;
        if (loadFactor > 0.7) { // Rehash if load factor exceeds 0.7
            rehash();
        }
    }

    // Function to rehash: resize the table and reinsert items
    void rehash() {
        cout << "\nRehashing started...\n";

        int oldTableSize = tableSize;
        vector<DataItem*> oldHashArray = hashArray;

        // Double the table size
        tableSize *= 2;
        hashArray.clear();
        hashArray.resize(tableSize, nullptr);
        currentSize = 0;

        // Reinsert all valid items into the new hash table
        for (int i = 0; i < oldTableSize; i++) {
            if (oldHashArray[i] != nullptr && oldHashArray[i]->key != -1) {
                insert(oldHashArray[i]->key, oldHashArray[i]->data);
                delete oldHashArray[i]; // Free old item memory
            }
        }

        cout << "Rehashing completed. New table size: " << tableSize << endl;
    }

public:
    // Constructor to initialize the hash table
    HashTable() : tableSize(INITIAL_SIZE), currentSize(0) {
        hashArray.resize(tableSize, nullptr);
        dummyItem = new DataItem{-1, -1};
    }

    // Destructor to clean up dynamically allocated memory
    ~HashTable() {
        for (auto item : hashArray) {
            if (item != nullptr && item != dummyItem) {
                delete item;
            }
        }
        delete dummyItem;
    }

    // Function to insert an item into the hash table
    void insert(int key, int data) {
        DataItem* item = new DataItem{key, data};
        int hashIndex = hashCode(key);

        // Handle collisions using linear probing
        while (hashArray[hashIndex] != nullptr && hashArray[hashIndex]->key != -1) {
            hashIndex = (hashIndex + 1) % tableSize;
        }

        hashArray[hashIndex] = item;
        currentSize++;

        // Check if rehashing is needed
        checkLoadFactor();
    }

    // Function to search for an item by its key
    DataItem* search(int key) {
        int hashIndex = hashCode(key);

        // Search for the key using linear probing
        while (hashArray[hashIndex] != nullptr) {
            if (hashArray[hashIndex]->key == key) {
                return hashArray[hashIndex];
            }
            hashIndex = (hashIndex + 1) % tableSize;
        }

        return nullptr; // Key not found
    }

    // Function to delete an item by its key
    void deleteItem(int key) {
        int hashIndex = hashCode(key);

        // Search for the key using linear probing
        while (hashArray[hashIndex] != nullptr) {
            if (hashArray[hashIndex]->key == key) {
                delete hashArray[hashIndex]; // Free memory
                hashArray[hashIndex] = dummyItem; // Mark slot as deleted
                currentSize--;
                return;
            }
            hashIndex = (hashIndex + 1) % tableSize;
        }

        cout << "\nKey " << key << " not found for deletion.";
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (hashArray[i] != nullptr && hashArray[i]->key != -1) {
                cout << "(" << hashArray[i]->key << ", " << hashArray[i]->data << ") ";
            } else {
                cout << "~~ "; // Placeholder for empty slots
            }
        }
        cout << endl;
    }
};

// Main function to test the hash table
int main() {
    HashTable hashTable;

    // Insert items
    for (int i = 1; i <= 15; i++) {
        hashTable.insert(i, i * 10);
    }

    // Display hash table
    cout << "\nContents of Hash Table: ";
    hashTable.display();

    // Search for an item
    int keyToSearch = 10;
    cout << "\nSearching for key: " << keyToSearch << endl;
    DataItem* item = hashTable.search(keyToSearch);
    if (item != nullptr) {
        cout << "Element found: (" << item->key << ", " << item->data << ")\n";
    } else {
        cout << "Element not found.\n";
    }

    // Delete an item
    cout << "Deleting key: " << keyToSearch << endl;
    hashTable.deleteItem(keyToSearch);
    cout << "Contents of Hash Table after deletion: ";
    hashTable.display();

    return 0;
}

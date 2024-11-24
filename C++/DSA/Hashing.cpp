#include <iostream>
#include <vector>
using namespace std;

#define TABLE_SIZE 10 // Fixed size of the hash table

// DataItem struct represents an element in the hash table
struct DataItem {
    int key;
    int data;
};

// HashTable class implementing a basic hash table
class HashTable {
private:
    vector<DataItem*> hashArray; // Vector to hold the hash table items
    DataItem* dummyItem;         // Dummy item to mark deleted slots

    // Hash function to calculate index based on the key
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    // Constructor to initialize the hash table
    HashTable() {
        hashArray.resize(TABLE_SIZE, nullptr);
        dummyItem = new DataItem{-1, -1}; // Dummy item for deletions
    }

    // Destructor to free memory
    ~HashTable() {
        for (auto item : hashArray) {
            if (item != nullptr && item != dummyItem)
                delete item;
        }
        delete dummyItem;
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int data) {
        DataItem* newItem = new DataItem{key, data};
        int index = hashFunction(key);

        // Linear probing to find an empty slot
        while (hashArray[index] != nullptr && hashArray[index] != dummyItem) {
            if (hashArray[index]->key == key) {
                // If key already exists, update the value
                hashArray[index]->data = data;
                delete newItem;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        hashArray[index] = newItem;
    }

    // Search for a value by its key
    int search(int key) {
        int index = hashFunction(key);

        // Linear probing to find the key
        while (hashArray[index] != nullptr) {
            if (hashArray[index]->key == key)
                return hashArray[index]->data; // Return the value
            index = (index + 1) % TABLE_SIZE;
        }
        return -1; // Key not found
    }

    // Delete a key-value pair from the hash table
    void remove(int key) {
        int index = hashFunction(key);

        // Linear probing to find the key
        while (hashArray[index] != nullptr) {
            if (hashArray[index]->key == key) {
                delete hashArray[index];      // Free memory for the item
                hashArray[index] = dummyItem; // Mark slot as deleted
                cout << "Key " << key << " deleted.\n";
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        cout << "Key " << key << " not found.\n";
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashArray[i] != nullptr && hashArray[i] != dummyItem)
                cout << " (" << hashArray[i]->key << ", " << hashArray[i]->data << ")";
            else
                cout << " ~~ "; // Placeholder for empty slots
        }
        cout << endl;
    }
};

int main() {
    HashTable hashTable;

    // Insert items into the hash table
    hashTable.insert(1, 20);
    hashTable.insert(2, 70);
    hashTable.insert(42, 80);
    hashTable.insert(4, 25);
    hashTable.insert(12, 44);

    // Display the hash table
    cout << "Hash Table contents: ";
    hashTable.display();

    // Search for an element
    int searchKey = 42;
    cout << "\nSearching for key " << searchKey << ": ";
    int result = hashTable.search(searchKey);
    if (result != -1)
        cout << "Found value: " << result << endl;
    else
        cout << "Key not found.\n";

    // Delete an element
    int deleteKey = 4;
    cout << "Deleting key " << deleteKey << "...\n";
    hashTable.remove(deleteKey);

    // Display the hash table after deletion
    cout << "Hash Table contents after deletion: ";
    hashTable.display();

    return 0;
}

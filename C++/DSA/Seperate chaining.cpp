#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Class for a hash table using separate chaining
class HashTable {
private:
    vector<list<pair<int, int>>> table; // Each index stores a linked list of (key, value) pairs
    int tableSize;

    // Hash function to compute the index
    int hashCode(int key) {
        return key % tableSize;
    }

public:
    // Constructor to initialize the hash table
    HashTable(int size) : tableSize(size) {
        table.resize(size);
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashCode(key);
        // Check if the key already exists and update its value
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // If key doesn't exist, add the new (key, value) pair
        table[index].emplace_back(key, value);
    }

    // Search for a value by its key
    bool search(int key, int& value) {
        int index = hashCode(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    // Delete a key-value pair by its key
    bool remove(int key) {
        int index = hashCode(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            for (const auto& pair : table[i]) {
                cout << "(" << pair.first << ", " << pair.second << ") -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

// Main function to test the hash table
int main() {
    HashTable hashTable(7);

    // Insert some key-value pairs
    hashTable.insert(1, 10);
    hashTable.insert(8, 20); // Collides with key 1
    hashTable.insert(15, 30); // Collides with key 1 and key 8
    hashTable.insert(2, 40);

    cout << "Hash Table after insertion:\n";
    hashTable.display();

    // Search for a key
    int value;
    if (hashTable.search(8, value)) {
        cout << "\nKey 8 found with value: " << value << endl;
    } else {
        cout << "\nKey 8 not found" << endl;
    }

    // Delete a key
    hashTable.remove(8);
    cout << "\nHash Table after deleting key 8:\n";
    hashTable.display();

    return 0;
}

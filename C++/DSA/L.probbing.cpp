#include <iostream>
#include <vector>
using namespace std;

#define EMPTY_KEY -1
#define DELETED_KEY -2

// Class for a hash table using open addressing and linear probing
class HashTable {
private:
    vector<pair<int, int>> table; // Stores (key, value) pairs
    int tableSize;
    int currentSize;

    // Hash function to compute the index
    int hashCode(int key) {
        return key % tableSize;
    }

public:
    // Constructor to initialize the hash table
    HashTable(int size) : tableSize(size), currentSize(0) {
        table.resize(size, {EMPTY_KEY, 0});
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) {
        if (currentSize == tableSize) {
            cout << "Hash table is full!" << endl;
            return;
        }

        int index = hashCode(key);
        // Find the next available slot
        while (table[index].first != EMPTY_KEY && table[index].first != DELETED_KEY) {
            if (table[index].first == key) { // Update value if key exists
                table[index].second = value;
                return;
            }
            index = (index + 1) % tableSize; // Linear probing
        }

        table[index] = {key, value};
        currentSize++;
    }

    // Search for a value by its key
    bool search(int key, int& value) {
        int index = hashCode(key);
        int originalIndex = index;

        // Search for the key using linear probing
        while (table[index].first != EMPTY_KEY) {
            if (table[index].first == key) {
                value = table[index].second;
                return true;
            }
            index = (index + 1) % tableSize;

            // Stop if we've come full circle
            if (index == originalIndex) {
                break;
            }
        }
        return false;
    }

    // Delete a key-value pair by its key
    bool remove(int key) {
        int index = hashCode(key);
        int originalIndex = index;

        // Search for the key using linear probing
        while (table[index].first != EMPTY_KEY) {
            if (table[index].first == key) {
                table[index].first = DELETED_KEY; // Mark the slot as deleted
                currentSize--;
                return true;
            }
            index = (index + 1) % tableSize;

            // Stop if we've come full circle
            if (index == originalIndex) {
                break;
            }
        }
        return false;
    }

    // Display the contents of the hash table
    void display() {
        for (int i = 0; i < tableSize; i++) {
            if (table[i].first == EMPTY_KEY) {
                cout << i << ": ~~" << endl;
            } else if (table[i].first == DELETED_KEY) {
                cout << i << ": DEL" << endl;
            } else {
                cout << i << ": (" << table[i].first << ", " << table[i].second << ")" << endl;
            }
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

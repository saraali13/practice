#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Find the next prime number greater than or equal to `n`
int nextPrime(int n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

class HashTable {
private:
    vector<int> table;
    int tableSize;
    int numElements;
    const int EMPTY = -1;

    // Primary hash function
    int hashFunction(int key) {
        return key % tableSize;
    }

    // Rehash the table when the load factor threshold is exceeded
    void rehash() {
        cout << "\nRehashing... Resizing table!" << endl;

        int oldTableSize = tableSize;
        vector<int> oldTable = table;

        // Find the new table size as the next prime number
        tableSize = nextPrime(2 * oldTableSize);
        table.assign(tableSize, EMPTY);
        numElements = 0;

        // Rehash all elements from the old table
        for (int i = 0; i < oldTableSize; i++) {
            if (oldTable[i] != EMPTY) {
                insert(oldTable[i]);
            }
        }
    }

public:
    HashTable(int size) : tableSize(size), numElements(0) {
        table.assign(tableSize, EMPTY);
    }

    // Insert an element into the hash table
    void insert(int key) {
        if ((float)numElements / tableSize >= 0.75) {
            rehash();
        }

        int index = hashFunction(key);

        // Find the next available slot
        while (table[index] != EMPTY) {
            index = (index + 1) % tableSize; // Linear probing
        }

        table[index] = key;
        numElements++;
    }

    // Search for an element in the hash table
    int search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != EMPTY) {
            if (table[index] == key) {
                return index;
            }
            index = (index + 1) % tableSize;
            if (index == start) break; // Full loop
        }
        return -1; // Not found
    }

    // Delete an element from the hash table
    void deleteElement(int key) {
        int index = search(key);
        if (index != -1) {
            table[index] = EMPTY; // Mark slot as empty
            numElements--;
        }
    }

    // Display the hash table
    void display() {
        cout << "Hash Table: ";
        for (int i = 0; i < tableSize; i++) {
            if (table[i] == EMPTY) {
                cout << "[ ] ";
            } else {
                cout << "[" << table[i] << "] ";
            }
        }
        cout << endl;
    }
};

int main() {
    // Initialize hash table with a size of 5
    HashTable ht(5);

    // Insert elements
    cout << "Inserting elements: 10, 20, 30, 40, 50, 60" << endl;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(60);
    ht.display();

    // Search for elements
    cout << "\nSearching for elements: 30, 50, 70" << endl;
    vector<int> searchKeys = {30, 50, 70};
    for (int key : searchKeys) {
        int result = ht.search(key);
        if (result != -1) {
            cout << "Key " << key << " found at index " << result << endl;
        } else {
            cout << "Key " << key << " not found.\n";
        }
    }

    // Delete elements
    cout << "\nDeleting elements: 20, 40" << endl;
    ht.deleteElement(20);
    ht.deleteElement(40);
    ht.display();

    // Insert additional elements to trigger rehashing
    cout << "\nInserting elements: 70, 80" << endl;
    ht.insert(70);
    ht.insert(80);
    ht.display();

    return 0;
}

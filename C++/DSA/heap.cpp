#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Restore heap property going up
    void heapifyUp(int index) {
        if (index == 0) return; // Base case: root node

        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent); // Recursively heapify the parent
        }
    }

    // Restore heap property going down
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // Check if the left child is larger
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check if the right child is larger
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // If the largest is not the current node, swap and continue heapifying
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);        // Add the new value to the end
        heapifyUp(heap.size() - 1);  // Restore the heap property
    }

    // Delete the root element from the heap
    void deleteRoot() {
        if (heap.empty()) return;

        heap[0] = heap.back(); // Replace root with the last element
        heap.pop_back();       // Remove the last element
        heapifyDown(0);        // Restore the heap property
    }

    // Search for an element in the heap
    bool search(int value) {
        for (int i : heap) {
            if (i == value) return true;
        }
        return false;
    }

    // Heap sort: Sort the heap elements
    vector<int> heapSort() {
        vector<int> sortedHeap;
        vector<int> originalHeap = heap; // Backup the heap

        while (!heap.empty()) {
            sortedHeap.push_back(heap[0]); // Add the root to sorted list
            deleteRoot();                  // Remove the root
        }

        heap = originalHeap; // Restore the original heap
        return sortedHeap;
    }

    // Print the heap
    void printHeap() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    // Insertion
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);
    heap.insert(8);
    heap.insert(9);

    cout << "Heap after insertions: ";
    heap.printHeap();

    // Searching
    cout << "Search 5 in heap: " << (heap.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search 15 in heap: " << (heap.search(15) ? "Found" : "Not Found") << endl;

    // Deleting root
    cout << "Heap after deleting root: ";
    heap.deleteRoot();
    heap.printHeap();

    // Sorting
    vector<int> sortedHeap = heap.heapSort();
    cout << "Heap after sorting: ";
    for (int val : sortedHeap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

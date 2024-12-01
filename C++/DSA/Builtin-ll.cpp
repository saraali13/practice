#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> linkedList = {10, 20, 30, 40};

    // Insert elements
    linkedList.push_back(50);
    linkedList.push_front(5);

    // Display elements
    cout << "Linked List: ";
    for (int val : linkedList) {
        cout << val << " ";
    }
    cout << endl;

    // Remove elements
    linkedList.pop_front();
    linkedList.pop_back();

    cout << "After removing front and back: ";
    for (int val : linkedList) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

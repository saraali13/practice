#include <iostream>
#include <stdexcept> // For std::out_of_range

class DynamicSafeArray {
private:
    int* data;
    size_t capacity;

public:
    // Constructor
   #include <iostream>
using namespace std;

class ResizingStack 
{
private:
    int* stack;      // Dynamic array to store stack elements
    int capacity;    // Capacity of the array (total allocated size)
    int top;         // Index of the top element in the stack

    // Function to resize the array when it gets full or underutilized

    void resize(int newCapacity) 
{
      //new capacity will be capacity/2 or /4 
  
        int* newStack = new int[newCapacity];
        for (int i = 0; i < top; i++) {
            newStack[i] = stack[i];
        }
        delete[] stack;  // Free the old array
        stack = newStack;  // Point to the new array
        capacity = newCapacity;
    }

public:
    // Constructor
    ResizingStack(int initCapacity = 4) : capacity(initCapacity), top(0) {
        stack = new int[capacity];
    }

    // Destructor
    ~ResizingStack() {
        delete[] stack;
    }

    // Push operation to add element to the stack
    void push(int value) {
        if (top == capacity) {
            // Double the capacity when the array is full
            resize(2 * capacity);
        }
        stack[top++] = value;
    }

    // Pop operation to remove the top element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
        if (top > 0 && top == capacity / 4) {
            // Shrink the capacity when the stack is 1/4 full (optional)
            resize(capacity / 2);
        }
    }

    // Peek operation to get the top element
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return stack[top - 1];
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == 0;
    }

    // Get the current size of the stack (number of elements)
    int size() const {
        return top;
    }

    // Get the current capacity of the stack
    int getCapacity() const {
        return capacity;
    }
};

int main() {
    ResizingStack s;

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << "Current stack size: " << s.size() << endl;
    cout << "Current stack capacity: " << s.getCapacity() << endl;

    // Push more elements, triggering a resize
    s.push(50);
    cout << "After resizing, stack capacity: " << s.getCapacity() << endl;

    // Peek the top element
    cout << "Top element: " << s.peek() << endl;

    // Pop elements from the stack
    s.pop();
    s.pop();
    cout << "Stack size after pops: " << s.size() << endl;

    // Optional shrinking
    cout << "Stack capacity after shrinking: " << s.getCapacity() << endl;

    return 0;
}

    // Resize Array
    void resize(size_t newCapacity) {
        int* newData = new int[newCapacity];
        size_t minSize = (newCapacity < capacity) ? newCapacity : capacity;
        for (size_t i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    // Get Capacity
    size_t getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicSafeArray arr(5);

    for (size_t i = 0; i < arr.getCapacity(); ++i) {
        arr[i] = i * 10;
    }

    for (size_t i = 0; i < arr.getCapacity(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.resize(10);
    for (size_t i = 5; i < arr.getCapacity(); ++i) {
        arr[i] = i * 10;
    }

    for (size_t i = 0; i < arr.getCapacity(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

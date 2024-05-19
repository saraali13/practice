#include <iostream>
using namespace std;

int main() 
{
    int size = 3;
    string* arr = new string[size]; // Allocate an array 


    arr[0] = "hello"; 
    arr[1] = "world";  

    // Print elements
    for (int i = 0; i < size; ++i) 
    {
        if (!arr[i].empty()) {  // Check if the element is not null
            cout << arr[i] << endl;  // Print the string
        }
    }

  // Clean up
    delete[] arr;

    return 0;
}

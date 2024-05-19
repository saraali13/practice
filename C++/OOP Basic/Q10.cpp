#include <iostream>
#include <vector>
using namespace std;

//Q9 using vectors
int main() 
{
    int size = 3;
    vector <string> arr; // Allocate an array 


    arr[0] = "hello"; 
    arr[1] = "world";  

    // Print elements
    for (int i = 0; i < size; ++i) 
    {
        {  // Check if the element is not null
            cout << arr[i] << endl;  // Print the string
        }
    }

    return 0;
}

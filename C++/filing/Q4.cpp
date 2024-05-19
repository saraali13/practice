#include <iostream>
#include <fstream> // For file operations
#include <exception> // For exception handling

using namespace std;

int main() 
{
    try 
    {
        // Open the file for writing
        ofstream file("example.txt");

        // Check if the file is successfully opened
        if (!file.is_open()) 
        {
            throw runtime_error("Failed to open the file");
        }

        // Write some data to the file
        file << "Hello, World!\n";

        // Close the file
        file.close();

        // Open the file for reading
        ifstream inFile("example.txt");

        // Check if the file is successfully opened
        if (!inFile.is_open()) 
        {
            throw runtime_error("Failed to open the file for reading");
        }

        // Read data from the file
        string line;
        while (getline(inFile, line)) 
        {
            cout << line << endl;
        }

        // Close the file
        inFile.close();
    } 
    
    catch (const exception& e) 
    {
        // Handle any exceptions that occur during file operations
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

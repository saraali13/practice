#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string st;
    
    ifstream INN("sample.txt");//for reading from the file

    if (!INN) 
    {
    cerr << "File could not be opened" << endl;
    return 1;
    }

    while (getline(INN, st)) // for reading file till last line
    {
    cout << st << endl;
    }
    INN.close();
    

    return 0;
}

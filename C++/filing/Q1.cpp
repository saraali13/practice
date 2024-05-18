#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string st;
    ofstream Out("sample.txt");//for writing into the file
    Out<<"hi hello ";
    Out.close();
    ifstream INN("sample.txt");//for reading from the file
    //INN>>st; will read one one word
    getline(INN,st);//will read only one line 
    cout<<st;

    return 0;
}

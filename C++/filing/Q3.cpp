#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string st;
    st="hey its sara ali here";
    ofstream INN("sample.txt",ios::app);//for writing without removing previous content
    INN<<st;


    return 0;
}

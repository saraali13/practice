#include <iostream>
using namespace std;

int main()
{
    cout<<"start"<<endl;
    try{//trying a code that may cause an erroe
        cout<<"inside try block\n";
        throw 30;//use conditions and then throw 
        cout<<"this will not execute\n";//if thrown then the code after throw will not be executed
    }
    catch(int a)//the trown variable will be caught here 
    {
        cout<<"exception caught\nVAlue is: "<<a<<endl;//printing the value thrown
    }
    cout<<"end\n";
    return 0;
}

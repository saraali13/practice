#include <iostream>
using namespace std;

int main()
{
    cout<<"start"<<endl;
    try{
        cout<<"inside try block\n";
        cout<<"still insidee\n";
    }
    catch(int a)//will not be executed as nothing is thrown
    {
        cout<<"exception caught\nVAlue is: "<<a<<endl;
    }
    cout<<"end\n";
    return 0;
}

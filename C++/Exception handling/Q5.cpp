#include <iostream>
using namespace std;

void EXP(int test){
    try{
        if (test==2)
        throw test;
        if(test==1)
        throw "Value is 1";
        if (test ==0)
        throw 0.00;
    }
        catch(int a)//will work for integers sperately and should be declared beftore all exception caughting
    {
        cout<<"Exp == "<<a<<endl;
    }
    catch(...)
    {
        cout<<"Exp caught \n";
    }

    
}

int main()
{
   EXP(1);
   EXP(0);
   EXP(2);
   EXP(9);
   
    return 0;
}

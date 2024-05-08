#include <iostream>
using namespace std;

void EXP(int test){
    try{
        if (test)
        throw test;
        else 
        throw "Value is 0";
    }
    catch(int i){
        cout<<"Exp 1: "<<i<<endl;
    }
    catch(const char *str){
        cout<<"Exp 2: "<<str <<endl;
    }
}

int main()
{
   EXP(1);
   EXP(0);
   EXP(9);
   
    return 0;
}

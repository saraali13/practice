#include <iostream>
using namespace std;

class MyException{
       public:
    string Str;
    int num;

 
    MyException(string St,int n):Str(St),num(n){

    }

};

int main()
{
    int i;
    try {
        cout<<"Enter a positive number\n";
        cin>>i;
        if(i<0)
        {
            throw MyException("not positive",i);
        }
    }
    catch(MyException e){
        cout<<e.Str<<endl<<e.num<<endl;

    }
    return 0;
}

#include <iostream>
#include <exception>
using namespace std;

int main()
{
  int a,b,n;
  cin>>a>>b;
  try {
    if (b==0)
    {
        //throw 
    }
    else{
       n=a/b;
    }
  }
   catch (exception &e){
    cout<<e.what();//trow a garbage value as nothing is thrown
   }
    cout<<n<<endl;
    return 0;
}

#include <iostream>
using namespace std;

template <typename T, typename U>//making a generic function using templates
void printValue(T V1,U V2)//used 2 diffrent variable for representing 2data types at a time in a function
{
   cout<<"Addition of integer and float is: "<<V1+V2<<endl;
}

template<typename T>
void printValue(T V1)
{
    cout<<"Value: "<<V1<<endl;
} 
int main(){
    int a=2;
    float b=3.4;
    char c='s';
    printValue(a,b);
    printValue(c);

    return 0;
}

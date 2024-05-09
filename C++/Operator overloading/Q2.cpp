#include <iostream>
using namespace std;

int operator+(int a,int b)//not possible 
{
   return a*a+b*b;
}

int main() 
{
 int a=3,b=9;
 double c=9.8,d=2.1;
 int e=a+b;
 cout<<e;
}

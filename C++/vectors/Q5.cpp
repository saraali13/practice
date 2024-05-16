/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
void display(vector <T> &v)
{
   
   for (int i = 0; i < v.size(); i++)
   {
    cout<<v.at(i)<<"\t";
   }
   cout<<endl;
   
}
int main(){
    vector<int>vec1;//0 lenght vector
    vector<char>vec2(4);//4 =size of vector
    vector<char>vec3(vec2);//4 =size of vector based on vec 2
    vector<int>vec4(5,3);//5=size and all elemts=3
    
    display(vec1);
    display(vec2);
    display(vec3);
    display(vec4);
}

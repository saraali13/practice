/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void display(vector <int> &v)
{
   
   for (int i = 0; i < v.size(); i++)
   {
    cout<<v[i]<<"\t";
   }
   cout<<endl;
   
}
int main(){
    vector<int>vec1;
    int n;
    for (int i=0;i<6;i++)
    {
        cout<<"enter a number\n";
        cin>>n;
        vec1.push_back(n);
    }
    vec1.pop_back();//for removing the last element of vector
    display(vec1);
    
}

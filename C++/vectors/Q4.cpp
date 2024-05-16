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
    cout<<v.at(i)<<"\t";//data at ith place
   }
   cout<<endl;
   
}
int main(){
    vector<int>vec1;
    int n;
    for (int i=0;i<3;i++)
    {
        cout<<"enter a number\n";
        cin>>n;
        vec1.push_back(n);
    }
    //vec1.pop_back();
    display(vec1);
    vector<int>::iterator iter=vec1.begin();
    vec1.insert(iter+1,3,5);
    display(vec1);
}

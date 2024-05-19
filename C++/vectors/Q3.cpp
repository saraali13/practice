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
    for (int i=0;i<3;i++)
    {
        cout<<"enter a number\n";
        cin>>n;
        vec1.push_back(n);
    }
    //vec1.pop_back();
    display(vec1);
    vector<int>::iterator iter=vec1.begin();
    vec1.insert(iter,5);//will insrt 5 at the begining iter+1= 2nd place=-5
  // vec1.insert(vec1.begin(),5);//without iterator
   // vec1.insert(iter+1,3,5);//the 3= number of copies it will print 5 3 times after the first element of the vector
}

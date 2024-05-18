#include <iostream>
using namespace std;

template <class T>
class C1{
   T a;
   T b;
   public:
   C1(T a,T b)
   {
      this->a=a;
      this->b=b;
   }

  void display()
   {
     cout<<"a= "<<a<<"\nb= "<<b<<endl;
   }
};

template <>//specialized templates
class C1<string>//for string data type we've specialized the template class
{
private:
    string a;
    string b;
public:
    C1(string a,string b):a(a),b(b)
    {}
   void display()
   {
     cout<<"a= "<<a<<b<<"\nb= "<<b<<a<<endl;
   }
};

int main()
{
   C1<int> obj1(2,7);
   C1<char> obj2('s','a');
   C1<string> obj3("hi","bye");

   obj1.display();
   obj2.display();
   obj3.display();
   
    return 0;
}

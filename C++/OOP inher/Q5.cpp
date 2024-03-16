# include <iostream>
using namespace std;


//HIERARCHICAL INHERITANCE

class base{
    public:
    int a,b;
    void setdata(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
};

class der1: public base
{
   public:
    void display1(){
    cout<<"derived class 1 \n";
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
   }
};
class der2:public base
{
 public:
 void display2(){
 	cout<<"\nderived class 2 \n";
 	cout<<"a is "<<a<<endl;
 	cout<<"b is "<<b<<endl;
 }	
};
class der3:public base
{
 public:
 void display3(){
 	cout<<"\nderived class 3 \n";
 	cout<<"a = "<<a<<endl;
 	cout<<"b = "<<b<<endl;
 }	
};
int main (){
    der1 d1;
    d1.setdata(2,3);
    d1.display1();
    der2 d2;
    d2.setdata(5,8);
    d2.display2();
    der3 d3;
    d3.setdata(8,55);
    d3.display3();
}

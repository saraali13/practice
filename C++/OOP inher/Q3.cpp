# include <iostream>
using namespace std;


//multipal inheritance

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
   	int c,d;
   	void set(int c,int d)
   	{  this->c=c;
   	   this->d=d;
	}
   	
    void display(){
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
   }
};
class der2:public der1
{
 public:
 void display2(){
 	cout<<"value of c is "<<c<<endl;
 	cout<<"value of d is "<<d<<endl;
 }	
};
int main (){
    der2 d1;
    d1.setdata(2,3);
    d1.display();
    d1.set(6,8);
    d1.display2();
}

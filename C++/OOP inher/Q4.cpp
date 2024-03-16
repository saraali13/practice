# include <iostream>
using namespace std;


//multipal inheritance

class base1{
    public:
    int a,b;
    void setdata(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
};
class base2
{
   public:
   	int c,d;
   	void set(int c,int d)
   	{  this->c=c;
   	   this->d=d;
	}
   
};
class der2: public base1,public base2
{
 public:
 	
void display1(){
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
   }
 void display2(){
 	cout<<"value of c is "<<c<<endl;
 	cout<<"value of d is "<<d<<endl;
 }	
};
int main (){
    der2 d1;
    d1.setdata(2,3);
    d1.display1();
    d1.set(6,8);
    d1.display2();
}

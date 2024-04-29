#include <iostream>
using namespace std;

//using simple virtual funtions

class base//base class
{
	int x;
	public:
		virtual int sq(int x)//virtul function
	{
		return x*x;
	}
};

class derived1:public base//class derived from base class
{
	int x;
	public:
		int sq(int x)//funtion over ridded
		{
			x=x+3;
			return x*x;
		}
	
};
int main()
{
	base B1;
	derived1 D1;
	base* Bptr = & D1;//base pointer to derived class obj
	int a=Bptr->sq(2);//function calling in derived class through base class pointer
	cout<<"a= "<<a;
	a=B1.sq(2);//funtion calling in base class
	cout<<"\na= "<<a;
}

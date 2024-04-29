
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
class derived2:public base//class derived from base class
{
	int x;
	public:
		int sq(int x)//funtion over ridded
		{
			x=x+1;
			return x*x;
		}
	
};
class derived3:public derived1//class derived from derived 1 class
{
	int x;
	public:
		int sq(int x)//funtion over ridded
		{
			x=x+2;
			return x;
		}
	
};

int main()
{
	base B1;
	derived1 D1;
	derived2 D2;
	derived3 D3;
	
	//using same base class pointer for calling the overridded function in derived classes
	base* Bptr = & D1;//base pointer to derived class 1 obj
	int a=Bptr->sq(2);//function calling in derived class through base class pointer
	cout<<"a= "<<a;
	
	Bptr = & D2;//base pointer to derived class 2 obj
	a=Bptr->sq(2);//function calling in derived class through base class pointer
	cout<<"\na= "<<a;
	
  derived1 *D1ptr = & D3;//D1 pointer to derived class 3 obj
	a=D1ptr->sq(2);//function calling in derived class through base class pointer
	cout<<"\na= "<<a;
	
	a=B1.sq(2);//funtion calling in base class
	cout<<"\na= "<<a;
}

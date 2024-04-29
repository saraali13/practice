
#include <iostream>
using namespace std;

//using simple virtual funtions and identifing the imapct/use of virtual keyword

class base//base class
{
	int x;
	public:
		virtual void dis()//virtul function
	{
		cout<<"hello cutiesss\n";
	}
	void show()
	{
		cout<<"showing\n";
	}
};

class derived1:public base//class derived from base class
{
	int x;
	public:
	void dis()//virtul function
	{
		cout<<"hello cutiesss hehe\n";
	}
		void show()
	{
		cout<<"showing lol\n";
	}
	
};
class derived2:public base//class derived from base class
{
	int x;
	public:
		void dis()//virtul function
	{
		cout<<"hello cutiesss\n muahhh";
	}
	void show()
	{
		cout<<"showing XD\n";
	}
};

int main()
{
	base B1;
	derived1 D1;
	derived2 D2;

	base* Bptr = & D1;//base pointer to derived class 1 obj
	Bptr->dis();//derived class funtion class
	Bptr=& D2;
	Bptr->show();//base class fuction called

}

#include <iostream>
using namespace std;

void print(){
	cout<<"Hellooooo\n";
}
class Student{
	public:
	static int ID;
	string name;
	int b=3;
	mutable int c=1;
	const int a=4;

	void diplay(){
		cout<<name<<endl;
		cout<<a<<endl;
			
		}
    void jk(const int f) const{
	//	b=6; error
	   // f=0; error
    	cout<<"f is "<<f<<endl;
		cout<<"b is "<<b<<endl;
		c=8;
		cout<<"c is "<<c<<endl;
	
	
	}
	
	static void Id(){
			cout<<ID<<endl;
			print();
		//	jk();
			cout<<endl;
			//a++;
		}
	
};

int Student :: ID=2;
//int Student::a=2;

int main (){
	Student S1,S2;
	S1.name="Sara";
	S2.name="Ali";
	S1.diplay();
	S1.Id();
	S2.ID=9;
	S2.diplay();
	S2.Id();
	S1.jk(9);
	Student xc;
	Student *ptr=&xc;
	ptr->name="sd";
	ptr->diplay();
	const int ga=7;
	const int *yut=&ga;
	cout<<"jje "<<*yut;
	int va=9;
	int *const yt=&va;
	cout<<"\njje "<<*yt;
	
}

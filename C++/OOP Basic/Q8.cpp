#include <iostream>
using namespace std;

class Student{

	int ID;
	string name;
	int *ptr;
	public:
	//deep copy constructors

	Student(int x,int y,string nm)
	{   
	    ID=y;
	    name=nm;
		ptr=new int;
		*ptr=x;

	}
	Student (const Student& Stu)
	{
		ptr=new int;
		*ptr=*(Stu.ptr);
		ID=Stu.ID;
		name=Stu.name;
	}

    void display(){
    	cout<<"Name: "<<name;
    	cout<<"\nID: "<<ID<<endl;
        cout<<"ptr= "<<*ptr<<endl;
	}

};

int main ()
{

	Student S3(4,9,"Ali");
	S3.display();
	Student S4(S3);
	S4.display();

	
}

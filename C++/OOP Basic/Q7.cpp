#include <iostream>
using namespace std;

//inline int product(int x,int y){
//	return x*y;
//}
class Student{

	int ID;
	string name;
	int *ptr;
//	int b=3;
	public:
		//default constructor
	Student():ID(0),name(""){
	}
	   //parameterized constructor
	Student (int ID,string name){
		this->ID=ID;
		this->name=name;
	}
	  //copy constructor if it wont be created then compiler will create its own copy constructor(shallow copy) 
	Student(const Student& stud){
		ID=stud.ID;
		name=stud.name;
	}
//parameterized constructor
	Student(int x)
	{
		ptr=new int;
		*ptr=x;

	}
	//deep copy constructor using dma	
	Student ( Student& Stu)
	{
		ptr=new int;
		*ptr=*(Stu.ptr);
	}
//	Student& gh(int a)
//	{
//		this->ID=a;
//		return *this;
//	}
    void display(){
    	cout<<"Name: "<<name;
    	cout<<"\nID: "<<ID<<endl;
    
	}
	void display2(){
		cout<<"ptr= "<<*ptr<<endl;
	}
	//destructor
	~ Student (){
		cout<<"destructor";
		delete [] ptr;
	}
	
};

//int Student :: ID=2;
//int Student::a=2;

int main ()
{
	Student S1(5,"Sara");
	S1.display();
//	Student S2(S1);
	//Student(S1);
//	S2.display();
	Student S3(4);
	S3.display2();
	Student S4(S3);
	S4.display2();
	
   // int pro=product(9,4);
    //cout<<"product is : "<<pro;
	
}

#include <iostream>
using namespace std;

void print(){
	cout<<"Hellooooo\n";
}
class Student{
	public:
	static int ID;
	string name;
	static int a;

	void diplay(){
		cout<<name<<endl;
			
		}
	static void jk(){
		cout<<"lalalalala\n";
		cout<<a<<endl;
	}
	
	static void Id(){
			cout<<ID<<endl;
			print();
			jk();
			cout<<endl;
			a++;
		}
	
};

int Student :: ID=2;
int Student::a=2;

int main (){
	Student S1,S2;
	S1.name="Sara";
	S2.name="Ali";
	S1.diplay();
	S1.Id();
	S2.ID=9;
	S2.diplay();
	S2.Id();
}

#include <iostream>
using namespace std;

void print(){
	cout<<"Hellooooo\n";
}
class Student{
	public:
	static int ID;
	string name;

	void diplay(){
		cout<<name<<endl;
			
		}
	static void jk(){
		cout<<"lalalalala\n";
	}
	
	static void Id(){
			cout<<ID<<endl;
			print();
			jk();
			cout<<endl;
		}
	
};

int Student :: ID=2;

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

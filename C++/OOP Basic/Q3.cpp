#include <iostream>
using namespace std;

class Student{
	public:
	static int ID;
	string name;

	void diplay(){
		cout<<name<<endl;
			
		}
		static void Id(){
			cout<<ID<<endl;
		}
	
};

int Student :: ID=2;

int main (){
	Student S1,S2;
	S1.name="sara";
	S2.name="Ali";
	S1.diplay();
	S1.Id();
	S2.ID=9;
	S2.diplay();
	S2.Id();
}

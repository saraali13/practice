#include <iostream>
using namespace std;

class Employee{
	public:
	string Name;
	string Company;
	int age;
	void intro(){
		cout<<"\nName: "<<Name;
		cout<<"\nCompany: "<<Company;
		cout<<"\nAge: "<<age;
	}
	
};
int main()
{
	Employee E1;
	E1.Name="jane";
	E1.Company="ytjhj";
	E1.age=23;
	E1.intro();
}

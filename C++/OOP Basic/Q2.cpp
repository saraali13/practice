#include <iostream>
using namespace std;

class Employee{
	public:
	string Name;
	string Company;
	int Age;
	void intro(){
		cout<<"Name: "<<Name;
		cout<<"\nCompany: "<<Company;
		cout<<"\nAge: "<<Age;
		cout<<endl;
		cout<<endl;
	}
	//Constructor
	Employee(string name, string company, int age){
		Name=name;
		Company=company;
		Age=age;
	}
};
int main()
{
	Employee E1=Employee("sara","uwudw",18);
	//E1.Name="jane";
	//E1.Company="ytjhj";
	//E1.Age=23;
	E1.intro();
	Employee E2=Employee("ali","sqjsh",23);
	E2.intro();
}

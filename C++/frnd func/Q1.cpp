#include <iostream>
using namespace std;

class A{
	private:
		int a;
		friend void func(A &b,int x);
};
void func(A &b,int x){
	A a1;
	a1.a=x;
	cout<<a1.a;
}
int main()
{
	A a1;
	func(a1,9);
}

#include <iostream>
using namespace std;

class Base{
	private:
		int a;
		public:
		Base(int x)
		{
			a=x;
		}
		Base operator+(Base obj){
			Base sum(0);
			sum.a=a+obj.a;
			return sum;
		}
		void display(){
			cout<<"The value is: "<<a;
		}
};
int main(){
	Base b1(3),b2(8);
	Base b3=b1+b2;
	b3.display();
	return 0;
}

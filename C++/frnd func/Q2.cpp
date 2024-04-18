#include <iostream>
using namespace std;

class Box{
	private:
		double width;
	public:
		friend void display(Box &b1);
		void setWidth(double w);
	//	{
	//		width=w;
	//	}
};
void display(Box &b1)
{
	cout<<"Width is: "<<b1.width<<endl;
}
void Box::setWidth(double w)
{
	width=w;
}
int main()
{
	Box box1;
	box1.setWidth(9.6);
	display(box1);

	return 0;
}

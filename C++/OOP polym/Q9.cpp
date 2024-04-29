#include <iostream>
using namespace std;

// Generic class using a template: class used for all data types

template<typename T>//can also use class istead of typename
class Pair {
private:
    T first;
    T second;
public:
    Pair(T f, T s) : first(f), second(s) {}
T sum()
{
	return first+second;
}
void display (){
	cout<<"first: "<<first<<endl;
	cout<<"second: "<<second<<endl;
}
};

int main() {
    // Creating objects of Pair class with different data types
    Pair<int> intobj(5, 10);
    Pair<double> doubleobj(3.590, 96.8);
    Pair<char> charobj('a', 'z');

int a=intobj.sum();
cout<<a<<endl;
intobj.display();

double b=doubleobj.sum();
cout<<b<<endl;
doubleobj.display();

char c=charobj.sum();
cout<<c<<endl;
charobj.display();

    return 0;
}

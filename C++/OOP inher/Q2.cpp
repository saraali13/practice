# include <iostream>
using namespace std;


//single inheritiance

class base{
    public:
    int a,b;
    void setdata(int a,int b)
    {
        this->a=a;
        this->b=b;
    }
};
class der: public base
{
   public:
   void display(){
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;
   }
};
int main (){
    der d1;
    d1.setdata(2,3);
    d1.display();
}

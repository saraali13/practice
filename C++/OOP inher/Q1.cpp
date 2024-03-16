# include <iostream>
using namespace std;

class base{
      string className;
      int classDuration;
      public:
      void setdata(string className,int classDuration)
      {
        this->className=className;
        this->classDuration=classDuration;
      }
      void display1()
      {
        cout<<"Name of class: "<<className<<endl;
        cout<<"Duration of class: "<<classDuration<<endl;
      }
};
class derived : public base
{
   string st_name;
   int st_rollNo;
   public:
    derived(string st_name,int st_rollNo)
      {
        this->st_name=st_name;
        this->st_rollNo=st_rollNo;
      }
      void display2()
      {
        cout<<"Name of student: "<<st_name<<endl;
        cout<<"Roll number of student: "<<st_rollNo<<endl;
      }
};
int main()
{
    derived d1("Ali",23);
    d1.setdata("oop",2);
    d1.display1();
    d1.display2();
}

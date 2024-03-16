# include <iostream>
using namespace std;

class base{ 
  public:

      string Name;
      int rollNo;
      base(string Name,int rollNo)
      {
        this->Name=Name;
        this->rollNo=rollNo;
      }
    //  void display1()
      //{
        //cout<<"Name of class: "<<className<<endl;
        //cout<<"Duration of class: "<<classDuration<<endl;
      //}
};
class derived : public base
{
   string name1;
   int rollNo1;
   public:
    derived(string name1,int rollNo1, string Name, int rollNo):base (Name,rollNo)
      {
        this->name1=name1;
        this->rollNo1=rollNo1;
      }
      void display()
      {
        cout<<"data of base class\n";
        cout<<"Name of student: "<<Name<<endl;
        cout<<"Roll number of student: "<<rollNo<<endl;
        cout<<"data of drived class\n";
        cout<<"Name of student: "<<name1<<endl;
        cout<<"Roll number of student: "<<rollNo1<<endl;
      }
};
int main()
{
    derived d1("Ali",23,"asad",45);
    d1.display();
}

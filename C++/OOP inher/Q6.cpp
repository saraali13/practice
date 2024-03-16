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
class basee{
    public:

      string Name1;
      int rollNo3;
      basee(string Name1,int rollNo3)
      {
        this->Name1=Name1;
        this->rollNo3=rollNo3;
      }

};
class derived : public base, public basee
{
   string name1;
   int rollNo1;
   public:
    derived(string name1,int rollNo1, string Name, int rollNo,string Name1,int rollNo3):base (Name,rollNo),basee(Name1,rollNo3)
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
        cout<<"data of basee class\n";
        cout<<"Name of student: "<<Name1<<endl;
        cout<<"Roll number of student: "<<rollNo3<<endl;
      }
};
int main()
{
    derived d1("Ali",23,"Sara",33,"john",78);
    d1.display();
}

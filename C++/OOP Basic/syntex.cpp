//get line func
getline(cin, author);
cin.ignore();

clss(const clss &obj)//copy constructor

//DMA
int * ptr= new int;
int *char=new int[size];

//Templates
template <typename T>
template <typename T, typename U>//for 2 diff data types
template <>//intead og T use a specific data type, will change its behaviour for that data type

template <typename T, int size>//non type arrgumet in generic class 
Array<double, 10> doubleArray;// in main (10=int fixed data type

class <int>obj1;//template in class generic class
//inheritance among genric classes
template <typename T>
class Cat : public Animal<T>

//static 
int car::m=1;//static data member initialization
void car::display(){}//coutside class function defination
car::display();//staticfunction calling without an object
float Account :: rateOfInterest = 6.5;//definig a static variable outside the class

//polymorphism
//overridig 
A *a;
B b;
a = &b;
a->show();

virtual void draw()//virtual funct

friend void dothis(class c1)//frnd function dec in class
friend class F;//frnd class dec in a class

class B:virtual public A//for solving diamond problem

//op overloading
class operator +(const class &C1){
  class t;
t.xyz=xyz+c1.xyz;
}

//exp handling
try {
  if blablabla
throw 1;//class can also be thrown trow c1/c2 an the obj of that class will be catch
}
  catch (int a)(...)//for bht sari conditions //catch(c1 c/c2 c)
    cout<<a;
  }
try {
  if blablabla
throw any type of exception defined in exception header file;
}
  catch (exception& e)//for bht sari conditions {
    cout<<e.what();
  }

//filing
ofstream/ifstream myfile("file.txt");//for opening a file in writing mode
ofstream my file; myfile.open("file.txt",std::mode);//by using open function file will be created if it is not already existing
if (!myfile); if (!myfile.is_open())//checking the opening of a file
myfile<<"hi hello";//writing into the file 

getline(myfile,st);//st=variable of storing the data read from the file
then cout<<st;
while(! myfile.eof())//for reading till last of the file use while loop
  
myfile.read/wirte((char*)&obj,sizeof(obj))//obj=object of a class we're working in  
myfile.close();//closing the file 

//vectors
vector<int>vec1(size if any);
vector <int> v1={2,3,4};
vec1.push_back(n);//for entering data 
vec1.size()//for determinig the size of vector
vec1.pop_back()//for removing last element 
vec1.empty()//for checking if a vector is empty
vec1.clear()//for removing all elements of a vector
vec1.at(n);//for checking element at a position n
vec1.front/back();//for checking 1st and last element of a vector
vc1.erase(position)//for removing a specific number
v.resize(new size, new elements);
v1.swap(v2)//for swapping 2 vectors
vector<int>::iterator iter=vec1.begin();
vec1.insert(position/iter,num);//inserting a num use position without iterator
(vector <int> v1)//function parameter

  

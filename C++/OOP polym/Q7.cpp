#include <iostream>
using namespace std;

// Abstract Class: have atlest 1 pure virtual function but contains other implementations as well

class Animal {
public:

    virtual void sound() = 0;//pure virtual functio
    void sleep() //implementation o other functions
	{
        cout << "sogya yeh jahan\n";
    }
};

class Dog : public Animal {
public:
    void sound(){
        cout << "bhao bhao\n";
    }
};

class Cat : public Animal {
public:
    void sound(){
        cout << "meow meow\n";
    }
};

int main() {
    Dog dog;
    Cat cat;

// calling sleep function in animal class(abstract class)

    dog.sound(); //function for dogs sound
    dog.sleep(); 
    cout<<endl;
    cat.sound(); // function for cats sound
    cat.sleep(); 

    return 0;
}

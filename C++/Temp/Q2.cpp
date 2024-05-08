#include <iostream>
using namespace std;

template <typename T>//making a generic function using templates
T maxElement(T *array,int size)
{
    T max=array[0];
    for (int i = 0; i < size; i++)
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }
    return max;
}

int main(){
    int intArray[]={2,3,4,5};
    double doubleArray[]={2.3,3.4,5.7,7.9,9.7};

    int Maxint=maxElement(intArray,4);//using generic function for int data type
    double Maxdouble=maxElement(doubleArray,5);//using generic function for double data type

    cout<<"Max element is intArray: "<<Maxint<<endl;
    cout<<"Max element in double array: "<<Maxdouble<<endl;

    return 0;
}

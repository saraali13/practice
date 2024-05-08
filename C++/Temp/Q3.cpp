#include <iostream>
using namespace std;

template <typename T>//making a generic class using templates
class WeatherData{
    T temperature;
    T humidity;
    T AirPressure;
    public:
    WeatherData(T temp,T hum,T AP):temperature(temp),humidity(hum),AirPressure(AP){

    }
    void Display(){
        cout<<"Temperature:" <<temperature<<endl<<"Humdity: "<<humidity<<endl<<"Air Pressure: "<<AirPressure<<endl;
    }
}; 

int main(){
    WeatherData<double> W1(3.4,5.6,7.9);//making objects of generic class of diffrent data types
    WeatherData<int> W2(3,5,2);
    W1.Display();
    W2.Display();
}

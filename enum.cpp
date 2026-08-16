#include <iostream>

using namespace std;

enum Color 
{
    Red = 200,
    Blue,
    Green
};

enum class TrafficLight 
{
    Red, 
    Yellow,
    Green
};

TrafficLight& operator++(TrafficLight& t)
{
    switch(t)
    {
        case TrafficLight::Red: return t = TrafficLight::Green;
            break;

        case TrafficLight::Yellow: return t = TrafficLight::Red;
            break;

        case TrafficLight::Green: return t = TrafficLight::Yellow;
            break;
    }
}


int main()
{
    Color c;
    c = Blue;

    if(c == 201)
    {
    cout << "YAYYYY!!" << endl;
    }
    
    Color d = Green;
    if(d == 1)
    {
    cout << "YAYYYY!!" << endl;
    }


    auto signal = TrafficLight::Red;
    TrafficLight next = ++signal;

    if(next == TrafficLight::Green)
    {
        cout << "signal turned green!!" << endl;
    }

}
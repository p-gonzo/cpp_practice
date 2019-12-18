#include <iostream>
using namespace std;

class Motor
{
private:
    int size;
public:
    Motor(int _size): size(_size) { }

    void SwitchIgnition()
    {
        cout << "Ignition ON" << endl;
    }

    void PumpFuel()
    {
        cout << "Fuel in cylinders" << endl;
    }

    void FireCylinders()
    {
        for (int i = 0; i < size; i ++)
            cout << "Vroom" << endl;
    }
};

class Car
{
private:
    Motor _motor;
public:
    Car(int _size): _motor(_size) { }

    void Drive()
    {
        _motor.SwitchIgnition();
        _motor.PumpFuel();
        _motor.FireCylinders();
    }
};

int main()
{
    Car myCar(3);
    myCar.Drive();

    return 0;
}
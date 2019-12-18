#include <iostream>
using namespace std;

class Motor
{
public:
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
        cout << "Vroom" << endl;
    }
};

class Car: private Motor
{
public:
    void Move()
    {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};

class Car2: protected Motor
{
public:
    void Move()
    {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};

class RaceCar: private Car2 // b/c Car2 has protected inheritance from Motor, it can pass the inhereted members on
{
public:
    void Move() {
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
        FireCylinders();
        FireCylinders();
    }
};

int main()
{
    Car myDreamCar;
    myDreamCar.Move();

    cout << endl;

    RaceCar myRaceCar;
    myRaceCar.Move();
    
    return 0;
}
#include <iostream>
using namespace std;

class Fish
{
public:
    bool isFreshWaterFish;

    void Swim()
    {
        cout << "Swims in " << (isFreshWaterFish ? "lake" : "sea") << endl;
    }
};

class Tuna: public Fish
{
public:
    Tuna()
    {
        isFreshWaterFish = false;
    }
};

class Carp: public Fish
{
public:
    Carp()
    {
        isFreshWaterFish = true;
    }
};

int main()
{
    Carp myLunch;
    Tuna myDinner;

    cout << "About my meals:" << endl;
    cout << "Lunch: ";
    myLunch.Swim();
    cout << "Dinner: ";
    myDinner.Swim();
    
    return 0;
}
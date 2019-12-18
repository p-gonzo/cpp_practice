#include <iostream>
using namespace std;

class Eggs
{
public:
    Eggs()
    {
        cout << "Constructing base member" << endl;
    }

    ~Eggs()
    {
        cout << "Destructing base member" << endl;
    }
};

class Fish
{
protected:
    bool isFreshWater; // accessable to only self, derived classes, and friends
    Eggs eggs;
public:

    Fish()
    {
        cout << "Constructing base" << endl;
    }
    ~Fish()
    {
        cout << "Destructing base" << endl;
    }
    void Swim()
    {
        cout << "Swims in a " << (isFreshWater ? "lake" : "sea") << endl;
    }
};

class Tuna : public Fish
{
public:
    Tuna()
    {
        cout << "constructing derived" << endl;
        isFreshWater = false; // set protected member in base
    }

    ~Tuna()
    {
        cout << "destructing derived" << endl;
    }
};

int main()
{
    Tuna myLunch;
    cout << "My Lunch ";
    myLunch.Swim();

    // protected members are inaccessible outside class hierarchy
    //myLunch.isFreshWater = false;
    return 0;
}
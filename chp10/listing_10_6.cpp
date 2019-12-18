#include <iostream>
using namespace std;

class Fish
{
public:
    void Swim()
    {
        cout << "Im swiming !" << endl;
    }
    
    void Swim(bool _isFreshWater)
    {
        cout << "I swim in a " << (_isFreshWater ? "lake" : "sea") << endl;
    }
};

class Tuna : public Fish
{
public:
    void Swim()
    {
        cout << "Im a swimming Tuna!" << endl;
    }
};

class Carp : public Fish
{
public:
    using Fish::Swim; // un-hide all Swim() methods in base class

    void Swim()
    {
        cout << "Im a swiming Carp!" << endl;
    }
};

int main()
{
    Tuna tuna;
    tuna.Swim();
    // tuna.Swim(false); // compile failure
    tuna.Fish::Swim(false);

    Carp carp;
    carp.Swim();
    carp.Swim(true);
    return 0;
}
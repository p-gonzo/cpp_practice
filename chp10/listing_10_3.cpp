#include <iostream>
using namespace std;

class Fish
{
private:
    bool isFreshWater;
public:
    Fish(bool _isFreshWater): isFreshWater(_isFreshWater) { }

    void Swim()
    {
        cout << "Swims in a " << (isFreshWater ? "lake" : "sea") << endl;
    }
};

class Carp : public Fish
{
public:
    Carp(): Fish(true) { }
};

class Tuna : public Fish
{
public:
    Tuna(): Fish(false) { }
};

int main()
{
    Carp carp;
    Tuna tuna;

    cout << "A carp";
    carp.Swim();

    cout << "A tuna";
    tuna.Swim();

    return 0;
}
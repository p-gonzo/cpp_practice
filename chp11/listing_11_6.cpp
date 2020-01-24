#include <iostream>
using namespace std;

class Fish
{
protected:
    int _stamina {3};
public:
    virtual void Swim() = 0;
};

class Tuna: public Fish
{
public:
    void Swim() override
    {
        for (int i = 0; i < _stamina; i ++)
        {
            cout << "Tuna swims fast in the sea!" << endl;
        }
    }
};

class Carp: public Fish
{
protected:
    int _stamina {2};
public:
    void Swim() override
    {
        for (int i = 0; i < _stamina; i ++)
        {
            cout << "Carp swims fast in the ocean!" << endl;
        }
    }
};

void MakeFishSwim(Fish &fish)
{
    fish.Swim();
}

int main()
{
    Tuna tuna;
    Carp carp;
    MakeFishSwim(tuna);
    MakeFishSwim(carp);
    return 0;
}
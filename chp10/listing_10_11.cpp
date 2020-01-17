#include <iostream>
using namespace std;

class Fish
{
public:
    void Swim()
    {
        cout << "Fish swims!" << endl;
    }

    virtual void Eat()
    {
        cout << "Fish eats!" << endl;
    }
};

class Tuna: public Fish
{
public: 
    void Swim()
    {
        cout << "Tuna swims!" << endl;
    }

    void Eat()
    {
        cout << "Tuna eats!" << endl;
    }
};

void MakeFishSwim(Fish &inputFish)
{
    inputFish.Swim();
}

void MakeFishEat(Fish &inputFish)
{
    inputFish.Eat();
}

int main()
{
    Tuna myDinner;

    myDinner.Swim();
    MakeFishSwim(myDinner);

    myDinner.Eat();
    MakeFishEat(myDinner); // use of virtual in Fish ensures overriding variant is called

    return 0;
}
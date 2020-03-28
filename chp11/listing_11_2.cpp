#include <iostream>
using namespace std;

class BasicFish
{
public:
    void Swim()
    {
        cout << "Fish Swims" << endl;
    }
};

class Fish
{
public:
    virtual void Swim()
    {
        cout << "Fish Swims" << endl;
    }
};

class Tuna: public Fish {
public:
    void Swim() override
    {
        cout << "Tuna Swims" << endl;
    }
};

class Carp: public Fish {
public:
    void Swim() override
    {
        cout << "Carp Swims" << endl;
    }
};

void MakeFishSwim(Fish& inputFish)
{
    inputFish.Swim();
}

int main()
{
    Fish fishes[3] = {Fish(), Tuna(), Carp()}; // We have narrowed our class here!

    for (auto fish: fishes) 
        MakeFishSwim(fish);

    cout << "---" << endl;

    for (int i = 0; i < sizeof(fishes) /sizeof(*fishes); ++i) {
        fishes[i].Swim();
    }

    cout << "---" << endl;

    Fish fish;
    Tuna tuna;
    Carp carp;

    Fish* fishPointers [3] = { &fish, &tuna, &carp };

    for (auto fishPointer: fishPointers)
        fishPointer->Swim();

    cout << "---" << endl;

    for (int i = 0; i < sizeof(fishPointers) /sizeof(*fishPointers); ++i) {
        fishPointers[i]->Swim();
    }
    
    cout << "---" << endl;

    cout << "sizeof(BasicFish) = " << sizeof(BasicFish) << endl; // smaller with no vptr attached
    cout << "sizeof(Fish) = " << sizeof(Fish) << endl;
    cout << "sizeof(Carp) = " << sizeof(Carp) << endl;

    return 0;
}

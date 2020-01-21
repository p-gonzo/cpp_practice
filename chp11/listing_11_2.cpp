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
    Fish fishes[3] = {Fish(), Tuna(), Carp()};

    Fish().Swim();
    Tuna().Swim();
    Carp().Swim();

    cout << "---" << endl;

    for (auto fish: fishes) // TODO - why doesn't this work?
        MakeFishSwim(fish);

    cout << "---" << endl;

    for (int i = 0; i < sizeof(fishes) /sizeof(*fishes); ++i) {
        fishes[i].Swim(); // TODO - why doesn't this work?
    }

    cout << "---" << endl;

    fishes[0].Swim();
    fishes[1].Swim();
    fishes[2].Swim();

    cout << "---" << endl;

    Fish fish;
    Tuna tuna;
    Carp carp;


    Fish* fishPointers [3] = { &fish, &tuna, &carp };
    fishPointers[0]->Swim();
    fishPointers[1]->Swim();
    fishPointers[2]->Swim();

    cout << "---" << endl;
    
    cout << sizeof(BasicFish) << endl; // smaller with no vptr attached
    cout << sizeof(Fish) << endl;


    return 0;
}
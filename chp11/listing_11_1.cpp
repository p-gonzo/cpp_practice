#include <iostream>
using namespace std;

class Fish
{
public:
    void Swim()
    {
        cout << "Fish Swims" << endl;
    }
};

class Tuna: public Fish {
public:
    void Swim()
    {
        cout << "Tuna Swims" << endl;
    }
};

void MakeFishSwim(Fish& inputFish)
{
    inputFish.Swim();
}

int main()
{
    Tuna tuna;
    tuna.Swim();
    MakeFishSwim(tuna);
    cout << sizeof(Tuna) << endl;
    return 0;
}
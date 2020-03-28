#include <iostream>

using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal Constructor" << endl;
    }

    int age;
};

class Mammal: public Animal { public: Mammal() { cout << "Mammal Constructed" << endl; } };
class Bird: public Animal { public: Bird() { cout << "Bird Constructed" << endl; } };
class Reptile: public Animal { public: Reptile() { cout << "Reptile Constructed" << endl; } };

class Platypus: public Mammal, public Bird, public Reptile
{
public:
    Platypus()
    {
        cout << "Platypus Constructor" << endl;
    }
};

int main()
{
    Platypus duckBilledP;
    // duckBilledP.age = 25;
    duckBilledP.Mammal::age = 25;

    // cout << duckBilledP.age << endl;
    return 0;
}

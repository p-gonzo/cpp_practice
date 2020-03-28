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

class Mammal: public virtual Animal { public: Mammal() { cout << "Mammal Constructed" << endl; } };
class Bird: public virtual Animal { public: Bird() { cout << "Bird Constructed" << endl; } };
class Reptile: public virtual Animal { public: Reptile() { cout << "Reptile Constructed" << endl; } };

class Platypus final: public Mammal, public Bird, public Reptile
{
public:
    Platypus()
    {
        cout << "Platypus Constructed" << endl;
    }
};

int main()
{
    Platypus duckBilledP;
    duckBilledP.age = 25;
    
    return 0;
}
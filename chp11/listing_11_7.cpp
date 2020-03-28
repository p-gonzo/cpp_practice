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

class Mammal: public Animal { };
class Bird: public Animal { };
class Reptile: public Animal { };

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
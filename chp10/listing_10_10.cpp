#include <iostream>
#include <string>
using namespace std;

class Mammal
{
private:

    string name;

public:

    Mammal(string _name): name(_name) { }

    void FeedBabyMilk()
    {
        cout << name << " feeds the baby some milk." << endl;
    }
};

class Reptile
{
private:

    string name;

public:

    Reptile(string _name): name(_name) { }

    void SpitVenom()
    {
        cout << name << " spits some venom" << endl;
    }
};

class Bird
{
private:

    string name;

public:

    Bird(string _name): name(_name) { }

    void LayEggs()
    {
        cout << name << " lays some eggs." << endl;
    }
};

class Platypus final: public Mammal, public Reptile, public Bird
{
private:
    string name;
public:
    Platypus(string _name): name(_name), Mammal(_name), Reptile(_name), Bird(_name) { }

    void Swim()
    {
        cout << name << " swims." << endl;
    }
};

int main()
{
    Platypus harry("Harry");
    harry.FeedBabyMilk();
    harry.LayEggs();
    harry.SpitVenom();
    harry.Swim();

    return 0;
}
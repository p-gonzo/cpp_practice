#include <iostream>
using namespace std;

class Human
{
protected:
    int age;

public:
    Human(int _age): age(_age) { }

    void Greet()
    {
        cout << "Hi, I'm " << (age > 40 ? age - 2 : age) << " years old" << endl;
    }

    void SayGoodbye()
    {
        cout << "It was nice to meet you!" << endl;
    }
};

class Diva : public Human
{
public:
    Diva(int _age): Human(_age) { }

    void Greet()
    {
        cout << "Hellloooo, I'm " << (age > 40 ? age - 2 : age) << " years young" << endl;
    }

    void SayGoodbye()
    {
        cout << "Peace, I'm out" << endl;
        Human::SayGoodbye(); // scop resolution operator
    }
};

int main()
{
    Human person(41);
    person.Greet();

    Diva diva(28);
    diva.Greet();

    diva.Human::Greet(); // scope resolution operator

    diva.SayGoodbye();
}

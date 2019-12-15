#include <iostream>
using namespace std;

class Human
{
    int age; // private in a class by default
public:
    // explicit constructor blocks implicit conversions
    explicit Human(int _age) : age(_age) {}
};

void DoSomething(Human person)
{
    cout << "Human did something" << endl;
    return;
}

int main()
{
    Human kid(10); // Explicit conversion, Ok
    Human anotherKid = Human(11); // Explicit conversion, Ok
    DoSomething(kid); // Ok

    // Human anotherKid2 = 11; // Failure: implicit conversion, NOT ok
    // DoSomething(10); // Failure: implicit conversion, NOT ok
    return 0;
}
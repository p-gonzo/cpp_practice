#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    string name;
    int age;
public:
    Human(string _name = "Adam", int _age = 30)
    :name(_name), age(_age)
    {
        cout << "Body of the constructor is empty." << endl;
    }

    void greet()
    {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
};

int main()
{
    Human adam;
    adam.greet();

    Human eve("Eve", 29);
    eve.greet();
    
    return 0;
}
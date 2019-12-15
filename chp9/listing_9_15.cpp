#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    friend class Utility;
    string name;
    int age;
public:
    Human(string _name, int _age)
        :name(_name), age(_age) {  }
};

class Utility
{
public:
    static void DisplayAge(const Human &person)
    {
        cout << person.age << endl;
    }
};

int main()
{
    Human firstMan("Adam", 25);
    cout << "Accessing private member age via friend class: ";
    Utility::DisplayAge(firstMan);
    return 0;
}

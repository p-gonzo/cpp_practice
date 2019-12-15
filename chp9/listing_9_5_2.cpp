#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    int age;
    string name;
public:
    Human(int _age = 31, string _name = "Phil")
    {
        age = _age;
        name = _name;
        cout << "This is still technically a default constructor" << endl;
    }

    void greet()
    {
        cout << "Hi! I'm " << name << " and I'm " << age << " years old" << endl;
    }
};

int main()
{
    Human newHuman;
    newHuman.greet();
    return 0;
}

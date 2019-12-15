#include <iostream> 
#include <string>
using namespace std;

class Human
{
private:
    string name;
    int age;

public:
    // Given the presense of an overloaded constructor, cpp does not create the default constructor for you
    Human(string _name, int _age)
    {
        name = _name;
        age = _age;
        cout << "Overloaded constructor call" << endl;
    }

    void IntroduceSelf()
    {
        cout << "I am " << name << " and I am " << age << " years old." << endl;
    }
};

int main()
{
    Human newHuman("Phil", 31);
    newHuman.IntroduceSelf();
    return 0;
}
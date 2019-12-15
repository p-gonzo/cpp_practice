#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    string name;
    int age;

    void IntroduceSelf()
    {
        cout << "I am " + name << " and am " << age << " years old." << endl;
    }

    ~Human()
    {
        cout << "I'm dying!" << endl;
    }
};

int main()
{
    Human firstMan;
    firstMan.age = 31;
    firstMan.name = "Adam";

    Human firstWoman;
    firstWoman.age = 29;
    firstWoman.name = "Eve";

    firstMan.IntroduceSelf();
    firstWoman.IntroduceSelf();

    return 0;
}

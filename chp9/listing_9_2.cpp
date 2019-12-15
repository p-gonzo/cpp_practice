#include <iostream>
using namespace std;

class Human
{
private:
    int age;
public:

    Human() = delete;

    Human(int inputAge)
    {
        if (inputAge > 0)
            age = inputAge;
        else
            age = 1;
    }
    
    int GetAge()
    {
        if (age > 30)
            return age - 2;
        else
            return age;
    }
};

int main()
{
    Human firstMan(35);
    Human firstWoman(22);

    cout << "Age of firstMan: " << firstMan.GetAge() << endl;
    cout << "Age of firstWoman: " << firstWoman.GetAge() << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Fish
{
public:
    Fish()
    {
        cout << "Constructed Fish" << endl;
    }

    virtual ~Fish() /* Without making the descructor virtual, we have a memory leak*/
    {
        cout << "Destructed Fish" << endl;
    }
};

class Tuna: public Fish
{
public:
    Tuna()
    {
        cout << "Constructed Tuna" << endl;
    }
    std::string val {"This is a value that is only held by a Tuna Fish"};

    ~Tuna()
    {
        cout << "Destructed Tuna" << endl;
    }
};

int main()
{
    Fish* pTuna = new Tuna;
    delete pTuna;
    return 0;
}
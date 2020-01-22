#include <iostream>
using namespace std;

class Fish
{
public:
    Fish()
    {
        cout << "Constructed Fish" << endl;
    }

    virtual ~Fish()
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

    ~Tuna() override
    {
        cout << "Destructed Tuna" << endl;
    }
};

void DealocateFishMemory(Fish *pFish)
{
    delete pFish;
}

int main()
{
    cout << "Tuna on the heap:" << endl;
    Tuna* pTuna = new Tuna;
    DealocateFishMemory(pTuna);

    cout << "---" << endl;
    cout << "Tuna on the stack:" << endl;
    Tuna tuna;

    return 0;
}
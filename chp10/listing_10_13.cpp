#include <iostream>
using namespace std;

class Fish
{
public:
    Fish()
    {
        cout << "Constructing Fish" << endl;
    }

    ~Fish()
    {
        cout << "Destructing Fish" << endl;
    }

    void swim() { // Fish* this
    }
private:
    int32_t _number;
};

class Tuna: public Fish
{
public:
    Tuna()
    {
        cout << "Constructing Tuna" << endl;
    }

    ~Tuna()
    {
        cout << "Destructing Tuna" << endl;
    }
};

void DeleteFishMemory(Fish *pFish)
{
    pFish->swim(); // Fish::swim(*pFish);
    delete pFish;
}

int main()
{
    cout << "A Tuna takes up " << sizeof(Tuna) << " bytes"<< endl;
    cout << "Allocating s Tuna on the free store:" << endl;
    Tuna *pTuna = new Tuna;
    cout << "Delting Tuna: " << endl;
    DeleteFishMemory(pTuna); // without the use of a virtual destructor on Fish, Tuna's destructor never gets called!

    cout << "Instantiating a tuna on the stack: " << endl;
    Tuna myDinner;
    cout << "Automatic destruction as it goes out of scope: " << endl;
    return 0;
}
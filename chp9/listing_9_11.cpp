#include <iostream>
using namespace std;

class MonsterDB
{
private:
    ~MonsterDB() {}; // private destructor prevents instances on the stack

public:
    static void DestroyInstance(MonsterDB *pInstance)
    {
        delete pInstance; // Member can invoke private destructor
        pInstance = nullptr;
    }

    void DoSomething()
    {
        cout << "Hello world" << endl;
    }
};

void doSomethingWithDB(MonsterDB *DBPtr)
{
    DBPtr->DoSomething();
}

int main()
{
    MonsterDB *myDB = new MonsterDB(); // on heap
    doSomethingWithDB(myDB);
    MonsterDB::DestroyInstance(myDB);
    // Theory:  Memory has been dealocated, so it MAY be overwritten, but hasn't been yet.
    // But why does setting to NULL after delete not fix this behavior?
    doSomethingWithDB(myDB);// TODO - Why doesn't this fail?
    doSomethingWithDB(myDB);// TODO - Why doesn't this fail?
    myDB->DoSomething();// TODO - Why doesn't this fail?
    return 0;
}
#include <iostream>
using namespace std;

void passByVal(int val);
void passByRef(int & val);
void passByPtr(int * val);
void doSomeStackAllocations();
int *getIntPtr();

int main()
{
    int x = 5;
    int *xptr = &x; // will not leak - TODO: So pointer points to memory on the stack?
    // int *xptr = new int(5); // will leak if not freed
    cout << "X = " << *xptr << endl;
    passByPtr(xptr);
    cout << "X = " << *xptr << endl;
    // delete xptr;
    int *dangerousPtr = getIntPtr();
    doSomeStackAllocations();
    cout << "The intPtr is: " << *dangerousPtr << endl;
    return 0;
}

void doSomeStackAllocations()
{
    int five = 5;
    char *message = "One day I went to sea.\n";
    cout << message << five << endl;
}

void passByVal(int val)
{
    val = 10;
    cout << "passByVal: val = " << val << endl;
}

void passByRef(int & ref)
{
    ref = 20;
    cout << "passByRef: ref = " << ref << endl;
}

void passByPtr(int * ptr)
{
    *ptr = 30;
    cout << "passByPtr: ptr = " << *ptr << endl;
}

int *getIntPtr()
{
    int y = 100;
    int *yptr = &y;
    // TODO - Should't y go out of scope after returning from this func?
    // Get valgrind error: Use of uninitialised value of size 8
    return yptr;
}
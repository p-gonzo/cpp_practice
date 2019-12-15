#include <iostream>
using namespace std;

inline void newline()
{
    cout << "\n";
}

int main()
{
    int age {31};
    int *pointsToInt = &age;
    newline();
    cout << "pointsToInt now points to age" << endl;
    cout << "The address of age is " << pointsToInt << endl;
    cout << "And we can access age using the dereference operator: " << *pointsToInt << endl;
    cout << "And the address of the pointer is " << &pointsToInt << endl;
    newline();
    int dogsAge {2};
    pointsToInt = &dogsAge;
    cout << "pointsToInt now points to dogsAge" << endl;
    cout << "The address of dogsAge is " << pointsToInt << endl;
    cout << "And we can access dogsAge using the dereference operator: " << *pointsToInt << endl;
    cout << "And the address of the pointer is " << &pointsToInt << endl;
    newline();
    
    return 0;
}
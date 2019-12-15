#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    int *pointsToAge = &age;
    int **pointsToPointsToAge = &pointsToAge;
    cout << "Integer 'age' is at: " << pointsToAge << endl;
    cout << "And it's value is: " << *pointsToAge << endl;
    cout << "And the address of the pointer is: " << &pointsToAge << endl;
    cout << "Using a pointer to a pointer we can access age: " << **pointsToPointsToAge << endl;

    return 0;
}
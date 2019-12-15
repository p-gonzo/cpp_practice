#include <iostream>
using namespace std;

int main()
{
    int* pointsToAnAge = new int;
    cout << "Enter your Dog's age: > ";
    cin >> *pointsToAnAge;

    cout << "Age " << *pointsToAnAge << " is stored at " << pointsToAnAge << endl;

    delete pointsToAnAge;

    return 0;
}
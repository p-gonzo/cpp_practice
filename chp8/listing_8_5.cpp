#include <iostream>
using namespace std;

int main()
{
    int dogsAge = 2;
    cout << "Initialized dogsAge = " << dogsAge << endl;
    int *pointsToAge = &dogsAge;
    cout << "PointsToAge points to dogsAge" << endl;

    cout << "Enter a new age for your dog: > ";
    cin >> *pointsToAge;

    cout << "Input stored at" << pointsToAge << endl;
    cout << "Integer dogsAge = " << dogsAge << endl;

    return 0;
}
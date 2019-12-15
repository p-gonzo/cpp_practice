#include <iostream>
using namespace std;

void CalcArea
(
    const double* const ptrPi, // const pointer and const data
    const double* const ptrRadius, // const pointer and const data
    double* const ptrArea // const pointer, however can change data
)
{
    if (ptrPi && ptrRadius && ptrArea)
        *ptrArea = (*ptrPi) * (*ptrRadius) * (*ptrRadius);
}

int main()
{
    const double Pi = 3.1416;

    cout << "Enter radius of circle: ";
    double radius {0};
    cin >> radius;

    double area {0};
    CalcArea(&Pi, &radius, &area);

    cout << "Area is = " << area << endl;

    return 0;
}
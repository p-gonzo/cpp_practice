#include <iostream>
#include <math.h>
using namespace std;

void Area(double radius, double &result)
{
    result = M_PI * pow(radius, 2);
}


int main()
{
    cout << "Enter a radius: > ";
    double radius {0.0}, result {0.0};
    cin >> radius;
    Area(radius, result);
    cout << "The Area of a circle with radus " << radius << " is " << result << endl;
    return 0;
}
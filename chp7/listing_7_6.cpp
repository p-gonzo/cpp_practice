#include <iostream>
#include <math.h>
using namespace std;

double Area(double radius);
double Area(double radius, double height);

int main()
{
    cout << "Enter a radius and a height separated by a single space: > ";
    double radius {0.0}, height{0.0};
    cin >> radius;
    cin >> height;

    cout << "The area of the circle is " << Area(radius) << endl;
    cout << "The area of the cylinder is " << Area(radius, height) << endl;

    return 0;
}

double Area(double radius)
{
    return M_PI * pow(radius, 2);
}

double Area(double radius, double height)
{
    return Area(radius) * height;
}
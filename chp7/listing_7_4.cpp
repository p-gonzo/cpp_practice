#include <iostream>
#include <math.h>
#include <string>

using namespace std;

double Area(double radius, double pi = 3.14);

int main()
{
    bool goAgain = true;

    while (goAgain)
    {
        double radius {0.0};
        string userInput = "";

        cout << "Let's get the area of a circle, enter the radius: ";
        getline(cin, userInput);
        radius = stod(userInput);
        
        cout << "Are you cool with the default pi value (3.14)? Enter a new val if not: ";
        getline(cin, userInput);

        if (userInput.empty())
        {
            cout << "The area with pi = 3.14 is: " << Area(radius) << endl;
        }
        else
        {
            cout << "The area with pi = " << stod(userInput) <<  " is: " << Area(radius, stod(userInput)) << endl;
        }

        cout << "Go again? (y/n) > ";
        getline(cin, userInput);
        goAgain = userInput[0] == 'y';
    }
    return 0;
}

double Area(double radius, double pi)
{
    return pi * (pow(radius, 2));
}
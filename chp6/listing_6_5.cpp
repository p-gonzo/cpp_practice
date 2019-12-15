#include <iostream>
using namespace std;

int main()
{

    enum DaysOfWeek
    {
        Sunday = 0,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    cout << "Find what days of the week are named after!" << endl;
    cout << "Enter a number for a day (Sunday = 0): " << endl;

    int dayInput = Sunday;
    cin >> dayInput;

    switch(dayInput)
    {
        case Sunday:
            cout << "The Sun" << endl;
            break;
        case Monday:
            cout << "The Moon" << endl;
            break;
        case Tuesday:
            cout << "Mars" << endl;
            break;
        case Wednesday:
            cout << "Murcury" << endl;
            break;
        case Thursday:
            cout << "Juputer" << endl;
            break;
        case Friday:
            cout << "Venus" << endl;
            break;
        case Saturday:
            cout << "Saturn" << endl;
            break;
        default:
            cout << "Wrong intput" << endl;
            break;

    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    char userSelection = 'x';
    do
    {
        cout << "Enter two ints: " << endl;
        int num1 = 0, num2 = 0;
        cin >> num1;
        cin >> num2;

        cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

        cout << "Press x to exit or any other key to recalculate." << endl;
        cin >> userSelection;

    } while (userSelection != 'x');
    
    return 0;
}
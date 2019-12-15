#include <iostream>
using namespace std;

int main()
{
    for (char userSelection = 'm'; userSelection != 'x';)
    {
        cout << "Enter an integer: ";
        int num1 {0};
        cin >> num1;

        cout << "Now another: ";
        int num2 {0};
        cin >> num2;

        cout << num1 << " x " << num2 << " = " << num1 * num2 << endl;

        cout << "Enter 'x' to quit or any other key to perform another calculation." << endl;
        cin >> userSelection;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    for(;;)
    {
        cout << "Enter two ints: ";
        int num1 = 0, num2 = 0;
        cin >> num1;
        cin >> num2;

        cout << "Do you wish to change your numbers (y/n)?" << endl;
        char changeNums {'n'};
        cin >> changeNums;

        if (changeNums == 'y') continue; // restart loop over

        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;

        cout << "Press x to exit or any other key to recalculate." << endl;
        char goAgain {'x'};
        cin >> goAgain;

        if (goAgain == 'x') break;
    }
    cout << "Goodbye!" << endl;
    return 0;
}
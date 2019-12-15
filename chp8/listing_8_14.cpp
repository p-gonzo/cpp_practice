#include <iostream>
using namespace std;

int main()
{
    cout << "Is it sunny (y/n)? ";
    char userInput {'y'};
    cin >> userInput;

    bool* const isSunny = new bool(true);

    if (userInput != 'y')
        *isSunny = false;
    
    cout << "Boolean flag sunny says: " << *isSunny << endl;

    delete isSunny;

    return 0;
}
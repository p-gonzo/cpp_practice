#include <iostream>
using namespace std;

int main()
{
    const int ARRAY_LENGTH {5};
    int myNums[ARRAY_LENGTH] = {0};

    cout << "Populate array of " << ARRAY_LENGTH << " integrers." << endl;

    for (int i = 0; i < ARRAY_LENGTH; ++i)
    {
        cout << "Enter an iteger for element " << i << ": ";
        cin >> myNums[i];
    }

    cout << "Dispalying conetents for myArray." << endl;

    for (int i = 0; i < ARRAY_LENGTH; ++i)
    {
        cout << "Element " << i << " = " << myNums[i] << endl;
    }
    
    return 0;
}
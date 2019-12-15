#include <iostream>
using namespace std;

int main()
{
    cout << "How many itegers shall I reserve memory for? > ";
    int numEntries = 0;
    cin >> numEntries;

    int *myNumbers = new int[numEntries];
    cout << "Memory allocated at: " << myNumbers<< endl;

    for (int i = 0; i < numEntries; ++i)
    {
        cout << "Enter a number at index " << i << ": ";
        int currentNumber {0};
        cin >> currentNumber;
        myNumbers[i] = currentNumber;
    }

    cout << "Printing your nums:" << endl;
    for (int i = 0; i < numEntries; ++i)
    {
        cout << myNumbers[i] << " ";
    }
    cout << endl;

    cout << "Printing your nums by incrementing the pointer:" << endl;
    for (int i = 0; i < numEntries; ++i)
    {
        int *currentNumLocation = myNumbers + i;
        cout << "The location of the current number is: " << currentNumLocation << " and it's value is: " << *currentNumLocation << endl;
    }
    cout << endl;

    cout << "De-allocating memory used for the int-array" << endl;
    delete[] myNumbers;

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    try
    {
        // request a LOT of memory
        int* pointsToTooManyNums = new int[0x1ffffffffff];
        // use allocated memory
        delete[] pointsToTooManyNums;

    }
    catch(bad_alloc)
    {
        cout << "Memory allocation failed." << endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    // Array size is too large, allocation will fail.
    // No throw will result in a NULL pointer
    int* pointsToTooManyNums = new(nothrow) int[0xfffffffffffffff];
    
    if (pointsToTooManyNums)
    {
        cout << "Memory allocation succeeded" << endl;
        delete[] pointsToTooManyNums;
    }
    else
    {
        cout << "Memory allocation failed" << endl;
    }
    
    return 0;
}
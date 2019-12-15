#include <iostream>
using namespace std;

int main()
{
    // An array IS a pointer to the first element
    int myNumbers[5] {2, 4, 6, 8, 10};
    int* pointsToNums = myNumbers;

    cout << "pointsToNums = " << pointsToNums << endl;
    cout << "&myNumbers = " << &myNumbers << endl;
    cout << "&myNumbers[0] = " << &myNumbers[0] << endl;

    cout << "myNumbers[2] = " << myNumbers[0] << " and *(pointsToNums + 2) = " << *(pointsToNums + 2) << endl;
    cout << "pointsToNums[2] = " << pointsToNums[0] << " and *(myNumbers + 2) = " << *(myNumbers + 2) << endl;

    // int moreNums[5] {0};
    // int *pointsToMoreNums = moreNums;
    // myNumbers = pointsToMoreNums; <- Invalid: lvalue is const (a pointer created when initializing an array is const)

    return 0;
}
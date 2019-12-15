#include <iostream>
using namespace std;

int main()
{
    cout << "How many ints do you want? > ";
    int intsRequested {0};
    cin >> intsRequested;

    int* pointsToIntsArr = new int[intsRequested];

    for (int i = 0; i < intsRequested; ++i)
    {
        cout << "Enter a number for int " << i << ": ";
        cin >> *(pointsToIntsArr + i);
    }

    cout << "Displaying all nums entered" << endl;

    for (int i = 0; i < intsRequested; ++i)
        cout << *(pointsToIntsArr++) << " ";
    cout << endl;

    cout << "Releasing memory..." << endl;
    pointsToIntsArr -= intsRequested; // need to place pointer back to the beginning of the arr
    delete[] pointsToIntsArr;
    return 0;
}
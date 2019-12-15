#include <iostream>
#include <algorithm>
using namespace std;
constexpr int Square(int num) { return num*num; };

int main()
{
    const int ARRAY_LENGTH = 5;

    int myNumbers [ARRAY_LENGTH] = {5, 10, 0, -101, 20};
    int moreNumbers [Square(ARRAY_LENGTH)];
    std::fill_n(moreNumbers, Square(ARRAY_LENGTH), 5);

    for (int intVal :moreNumbers)
    {
        cout << intVal << endl;
    }


    cout << "Enter index of the element to be changed: ";
    int elementIndex = 0;
    cin >> elementIndex;

    cout << "Enter new value: ";
    int newValue = 0;
    cin >> newValue;

    myNumbers[elementIndex] = newValue;
    moreNumbers[Square(elementIndex)] = newValue;

    cout << "Element " << elementIndex << " in array myNumbers is: " << myNumbers[elementIndex] << endl;
    cout << "Element " << Square(elementIndex) << " in array moreNumbers is: " << moreNumbers[Square(elementIndex)] << endl;

    return 0;
}
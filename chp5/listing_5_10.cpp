#include <iostream>
using namespace std;

int main()
{
    cout << "Use sizeof to determine memory used by arrays" << endl;

    uint8_t myNumbers[100] = {};

    cout << "Bytes used by an int: " << sizeof(uint8_t) << endl;
    cout << "Bytes used by myNumbers: " << sizeof(myNumbers) << endl;
    cout << "Bytes used by an element in myNumbers: " << sizeof(myNumbers[0]) << endl;

    return 0;
}
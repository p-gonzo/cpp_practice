#include <iostream>
using namespace std;

inline long DoubleNum (int inputNum) // Request compiler to place function inline, rather than a CALL instruction
{
    return inputNum * 2;
}

int main()
{
    cout << "Enter an int: ";
    int inputNum {0};
    cin >> inputNum;
    cout << "Doubled, that is: " << DoubleNum(inputNum) << endl;
    return 0;
}
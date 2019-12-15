#include <iostream>
using namespace std;

int getFibNumber(int fibIdx)
{
    if (fibIdx < 2)
        return fibIdx;
    else
        return getFibNumber(fibIdx - 1) + getFibNumber(fibIdx - 2);
}

int main()
{
    cout << "Enter 0-based index of desired Fibonacci number: > ";
    int idx;
    cin >> idx;
    cout << "The Fibonacci number at index " << idx << " is " << getFibNumber(idx) << "." << endl;
    return 0;
}
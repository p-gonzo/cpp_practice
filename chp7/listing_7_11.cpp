#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DisplayNums(vector<int> &dynArray)
{
    for_each(dynArray.begin(), dynArray.end(), [](int Element) { cout << Element << " "; });
    cout << endl;
}

int main()
{
    vector<int> myNums {-1, 25, -35, 501};
    DisplayNums(myNums);

    cout << "Sorting nums..." << endl;

    sort(myNums.begin(), myNums.end() , [](int num1, int num2) { return num2 < num1; });
    DisplayNums(myNums);
    return 0;
}
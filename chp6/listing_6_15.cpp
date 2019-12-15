#include <iostream>
using namespace std;

int main()
{
    int numsToCaluclate {5};
    int num1 {0}, num2 {1};
    char goAgain = 'n';

    do
    {
        for (int i = 0; i < numsToCaluclate; ++i)
        {
            cout << num1 << " ";
            int tmp = num2;
            num2 += num1;
            num1 = tmp;
        }
        cout << "Go again (y/n)?" << endl;
        cin >> goAgain;
    } while (goAgain == 'y');
    
    cout << "Goodbye! :)" << endl;
    return 0;
}
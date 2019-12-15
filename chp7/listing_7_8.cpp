#include <iostream>
using namespace std;

void DisplayArray(int numbers[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void DisplayArray(char chars[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << chars[i] << " ";
    }
    cout << endl;
}

// Todo, why do we pass the array by referece?
// Does that leave us with a pointer due to array decay?
template <typename T, size_t n>
void DisplayArray2(T (&items)[n]) // takes one argument, a reference to an array of type T and size n
{
    for (int i = 0; i < n; ++i)
    {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main()
{
    int numbers[] = {5, 10, 15, 20, 25, 30};
    DisplayArray(numbers, 6);

    char chars[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    DisplayArray(chars, 6);

    DisplayArray2<int>(numbers);
    DisplayArray2<char>(chars);


    return 0;
}
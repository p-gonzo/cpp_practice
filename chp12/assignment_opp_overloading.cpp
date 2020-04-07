#include <iostream>

class A
{
private:
    int i {5};

public:
    // operator int()
    // {
    //     i = 3;
    //     return i;
    // }

    // operator int() const
    // {
    //     return i;
    // }

    operator const int()
    {
        i = 3;
        return i;
    }

    // operator const int() const
    // {
    //     return i;
    // }
};

int main()
{
    A a;
    int b = a;
    b++;
    std::cout << b << std::endl;
}
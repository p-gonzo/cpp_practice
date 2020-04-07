#include <iostream>

class A
{
private:
    int i {5};

public:
    // operator int()
    // {
    //     return i;
    // }

    // operator int() const
    // {
    //     return i;
    // }

    // operator const int()
    // {
    //     return i;
    // }

    operator const int() const
    {
        return i;
    }
};

int main()
{
    A a;
    int b = a;
    b++;
    std::cout << b << std::endl;
}
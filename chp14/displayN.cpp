#include <iostream>
#include <string>

template <typename T1, typename T2>
void Display(const T1 &a, const T2 &b)
{
    std::cout << a << ", " << b << std::endl;
}

template <typename T1, typename... Tn>
void Display(const T1 &a, const Tn&... n)
{
    std::cout << a << ", ";
    return Display(n ...);
}


int main()
{
    std::string a { "Hello" };
    char b {'x'};
    int c { 5 };
    double d { 3.14 };

    Display(a, b);
    Display(c, d);

    Display(a, b, c, d);

    return 0;
}
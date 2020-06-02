#include <iostream>
#include <string>

template <typename ResType, typename ValType>
void Sum(ResType& res, const ValType& val)
{
    res += val;
}

template <typename ResType, typename First, typename... Rest>
void Sum(ResType& res, const First& val1, const Rest&... valN)
{
    res += val1;
    return Sum(res, valN ...);
}

int main()
{
    double num = 0;
    Sum(num, 3.14, 4.56, 1.1111);
    std::cout << num << std::endl;

    std::string str;
    Sum(str, "Hello", " world", " of", " variadic", " templates.");
    std::cout << str << std::endl;

    return 0;
}
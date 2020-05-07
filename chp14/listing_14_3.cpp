#include <iostream>

template<typename T, typename T2 = T>
const T2 max(const T& v1, const T2& v2)
{
    return v1 > v2 ? v1 : v2;
}

template <typename T, typename T2 = T>
void DisplayComparison(const T& v1, const T2& v2)
{
    std::cout << "max(" << v1 << ", " << v2 << ") = " << max<T, T2>(v1, v2) << std::endl;
}

int main()
{
    std::cout << "Enter an int: ";
    int int1 {0};
    std::cin >> int1;
    std::cout << "Enter a double: ";
    double dub {0};
    std::cin >> dub;
    DisplayComparison(int1, dub);

    return 0;
}
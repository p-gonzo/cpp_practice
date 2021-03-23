#include <iostream>

template <typename T>
void printBits(T &x)
{
    for (size_t i = 0; i < sizeof(x) * 8; ++i)
    {
        std::cout << (x & 1);
        x = x >> 1;
    }
    std::cout << std::endl;
}

template <typename T>
void setBits(T &x, T y)
{
    for (size_t i = 0; i < sizeof(x) * 8; ++i)
    {
        x = (x << 1) + (y & 1);
        y = y >> 1;
    }
}

int main()
{
    unsigned char x = 0;
    setBits<unsigned char>(x, 0xaa);
    printBits(x);
}
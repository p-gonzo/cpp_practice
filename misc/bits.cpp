#include <iostream>

void printBits(unsigned char &x)
{
    for (size_t i = 0; i < sizeof(x) * 8; ++i)
    {
        std::cout << (x & 1);
        x = x >> 1;
    }
    std::cout << std::endl;
}

void setBits(unsigned char &x, unsigned char y)
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
    setBits(x, 255);
    printBits(x);
}
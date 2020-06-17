#include <iostream>
#include <string>

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes" << std::endl;
    return malloc(size);
}

int main()
{
    std::cout << "making short name" << std::endl;
    std::string shortStr = "Phil";
    
    std::cout << "making 15 char name" << std::endl;
    std::string str = "Philip Gonzalez"; // 15 chars
    
    std::cout << "making name longer than 15 chars" << std::endl;
    std::string longStr = "Philip George Gonzalez"; // 22 chars
    
    return 0;
}
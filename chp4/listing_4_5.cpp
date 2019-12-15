#include <iostream>

int main()
{
    char sayHello[] = {'H', 'e', 'l', 'l','o', ' ', 'W', 'o', 'r', 'l', 'd', '.', '\0'};
    
    std::cout << "The size of the  sayHello character array is, " << sizeof(sayHello) << std::endl;
    std::cout << "Printing sayHello character array..." << std::endl;
    std::cout << sayHello << std::endl;
    
    std::cout << "Replacing space with null character" << std::endl;
    sayHello[5] = '\0';
    
    std::cout << "The size of the  sayHello character array is, " << sizeof(sayHello) << std::endl;
    std::cout << "Printing sayHello character array..." << std::endl;
    std::cout << sayHello << std::endl;

    std::cout << "Printing each character: " << std::endl;

    int bitIndex {0};
    int bitValue {0};

    for (char letter : sayHello)
    {
        std::cout << letter << " ";

        while (bitIndex < 8)
        {
            bitValue = (letter >> bitIndex) & 1;
            std::cout << bitValue << " ";
            bitIndex++;
        }
        bitIndex = 0;
        std::cout << std::endl;
    }
    
    return 0;
}
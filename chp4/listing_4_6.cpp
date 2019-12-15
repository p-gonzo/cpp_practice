#include <iostream>
#include <string.h>

int main()
{
    std::cout << "Enter a word not longer than 20 characters: " << std::endl;

    char userInput [21] = {'b', '\0'};
    std::cout << userInput << std::endl;
    std::cin >> userInput;
    std::cout << userInput << std::endl;

    std::cout << "Length of your input was: " << strlen(userInput) << std::endl;
    return 0;
}
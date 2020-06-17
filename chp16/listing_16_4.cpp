#include <iostream>
#include <string>

int main()
{
    std::string sample {"Good day string!  Today is beautiful!"};
    
    const char* target = "day";
    
    size_t charPos = sample.find(target, 0);
    if (charPos != std::string::npos)
    {
        std::cout << "First instance of '" << target << "' was found at postion " << charPos << std::endl;
    }
    else
    {
        std::cout << "Substring '" << target << "' was not found."  << std::endl;
    }

    std::cout << std::endl;

    charPos = sample.find(target, 0);
    while (charPos != std::string::npos)
    {
        std::cout << "'" << target << "' found at position " << charPos << std::endl;
        charPos = sample.find(target, ++charPos);
    }
    
    return 0;
}
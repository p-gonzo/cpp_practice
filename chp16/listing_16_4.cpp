#include <iostream>
#include <string>

int main()
{
    std::string sample {"Good day string!  Today is beautiful!"};
    size_t charPos = sample.find("day", 0);
    if (charPos != std::string::npos)
    {
        std::cout << "First instance of \"day\" was found at postion " << charPos << std::endl;
    }
    else
    {
        std::cout << "Substring \"day\" was not found."  << std::endl;
    }
    
    return 0;
}
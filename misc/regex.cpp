#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string prefix = "Ph";
    std::string name = "Philip";
    std::regex re(prefix + "([a-zA-Z0-9]){4}");
    if(name.size() != 6 && !std::regex_match(name, re))
    {
        std::cout << "no match" << std::endl;
    }
    else
    {
        std::cout << "match" << std::endl;
    }
    
    return 0;
}
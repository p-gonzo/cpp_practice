#include <iostream>
#include <string>
#include <sstream>

std::string genMessage(const char* message)
{
std::stringstream logMessage;
   logMessage << message << std::endl;
   return logMessage.str();
}


int main()
{
    std::cout << genMessage("hello world\0");
    return 0;
}
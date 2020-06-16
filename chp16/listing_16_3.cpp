#include <iostream>
#include <string>

int main()
{
    std::string str1 {"Hello"};
    std::string str2 {" world!"};

    str1 += str2;
    std::cout << str1 << std::endl;

    str1.append(" Fun is not needing to use pointers");
    std::cout << str1 << std::endl;

    const char * cStyleStr {" But you still can if you'd like\0"};

    str1.append(cStyleStr);
    std::cout << str1 << std::endl;
    
    return 0;
}
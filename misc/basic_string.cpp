#include <iostream>
#include <string>

using aString = std::basic_string<char, std::char_traits<char>, std::allocator<char>>;

int main()
{
    aString myStr {"Hello World!"};
    for (auto itr = myStr.begin(); itr < myStr.end(); ++ itr)
    {
        std::cout << *itr << std::endl;
    }
    return 0;
}
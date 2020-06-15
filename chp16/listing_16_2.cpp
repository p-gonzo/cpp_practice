#include <iostream>
#include <string>

int main()
{
    std::string phil {"Phil"};

    for (size_t i = 0; i < phil.length(); ++i)
    {
        std::cout << "phil[" << i << "] = " << phil[i] << std::endl;
    }

    std::cout << std::endl;

    for (auto itr = phil.begin(); itr != phil.end(); ++itr)
    {
        std::cout << "phil[" << distance(phil.begin(), itr)  << "] = " << *itr << std::endl;
    }

    std::cout << std::endl;

    const char* philCStr = phil.c_str();
    for (int i = 0; philCStr[i] != 0; ++i) // note: can also use strlen here
    {
        std::cout << philCStr[i] << std::endl;
    }
    return 0;
}
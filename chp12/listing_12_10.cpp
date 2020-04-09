#include <iostream> 
#include <string>

class Display
{
public:
    void operator () (std::string input) const
    {
        std::cout << input << std::endl;
    }
};

int main()
{
    Display displayFuncObj;

    displayFuncObj("Hello");
    displayFuncObj.operator()("World");
    return 0;
}
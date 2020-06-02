#include <iostream>
#include <string>

struct MyClass
{
    static std::string staticVal;
};

std::string MyClass::staticVal { "Hello World" };

int main()
{
    MyClass myInstance;
    std::cout << myInstance.staticVal << std::endl;
    return 0;
}


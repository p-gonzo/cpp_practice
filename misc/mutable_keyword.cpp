#include <iostream>
#include <string>

class MyKlass
{
public:
    MyKlass(std::string name): _name(name) { };
    const std::string & GetName() const
    {
        ++callCount;
        return _name;
    }
    mutable unsigned int callCount { 0 };
private:
    std::string _name;
};

int main(int argc, char** argv)
{
    const MyKlass person("Phil");
    std::cout << person.callCount << std::endl;
    std::cout << person.GetName() << std::endl;
    std::cout << person.callCount << std::endl;
}
#include <iostream>
#include <string>

class MyKlass
{
public:
    MyKlass(int val): _mem_val(val) { }
    void doAThing(int val, const std::string &str)
    {
        std::cout << _mem_val * val << " " << str << std::endl;
    }
private:
    int _mem_val { 0 };
};

int main()
{
    void (MyKlass::*func)(int val, const std::string &str)  = &MyKlass::doAThing;
    MyKlass myClass (3);
    (myClass.*func)(5, "hello"); // outputs "15 hello"
    return 0;
}
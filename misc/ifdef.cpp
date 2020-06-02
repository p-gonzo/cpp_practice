#include <iostream>
// #define MY_VAL

struct MyClass
{
    static void func()
    {   
        #ifdef MY_VAL
        std::cout << "defined" << std::endl;
        #else
        std::cout << "not defined" << std::endl;
        #endif
    }
};

int main()
{
    MyClass::func();
    return 0;
}
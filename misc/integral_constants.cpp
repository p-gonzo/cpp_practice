#include <type_traits>
#include <iostream>

struct myTrueType: std::true_type { };
struct MyFalseType: std::false_type { };

int main()
{
    const bool myFalse = MyFalseType::value;
    const bool myTrue = myTrueType::value;
    std::cout << myFalse << std::endl;
    std::cout << myTrue << std::endl;
    return 0;
}
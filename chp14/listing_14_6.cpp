#include <iostream>
#include <string>

template <typename T>
class TestStatic
{
public:
    static std::string staticVal;
};

// static member initialization with generic type
template<typename T>
std::string TestStatic<T>::staticVal { "Hello World!" };

int main()
{
    TestStatic<int> withInt;
    withInt.staticVal = "Template with int";

    TestStatic<double> withDouble;
    withDouble.staticVal = "Template with double";

    TestStatic<int> withInt2;
    std::cout << withInt2.staticVal << std::endl;

    TestStatic<double> withDouble2;
    std::cout << withDouble2.staticVal << std::endl;

    TestStatic<float> withFloat;
    std::cout << withFloat.staticVal << std::endl;
}
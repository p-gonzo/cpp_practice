#include <iostream>
#include <sstream>
#include <string>

class Temperature
{
private:
    double _kelvin;
    std::string _stringKelvin;
public:
    Temperature(long double k): _kelvin(k)
    {
        std::stringstream s;
        s << _kelvin;
        _stringKelvin = s.str();
    }
    
    operator const char*()
    {
        return _stringKelvin.c_str();
    }
};

// User Defined Literal Syntax
Temperature operator"" _C(long double celsius)
{
    return Temperature(celsius + 273);
}

// User Defined Literal Syntax
Temperature operator"" _F(long double fahrenheit)
{
    return Temperature((fahrenheit + 459.67) * 5 / 9 );
}

int main()
{
    Temperature k1 = 31.73_F;
    Temperature k2 = 0.0_C;

    std::cout << "k1 is " << k1 << " Kelvin" << std::endl;
    std::cout << "k2 is " << k2 << " Kelvin" << std::endl;

    return 0;
}
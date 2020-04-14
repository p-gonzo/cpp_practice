#include <iostream>
#include <sstream>
#include <string>

class DynIntegers
{
private:
    int* _ints;
    size_t _len;
    std::string _intString;
    DynIntegers() { std::cout << "Private default constructor called" << std::endl; }
public:
    DynIntegers(const int* input, const size_t len): _len(len)
    {
        if (input != NULL)
        {
            _ints = new int[_len];
            for (size_t i = 0; i < _len; ++i)
            {
                _ints[i] = input[i];
            }
        }
        else _ints = NULL;
    }

    ~DynIntegers()
    {
        std::cout << "Destructor called" << std::endl;
        if (_ints != NULL) delete[] _ints;
    }

    operator const char*()
    {
        std::ostringstream os;
        os << "{ ";
        for (size_t i = 0; i < _len; ++i)
        {
            os << _ints[i] << ", ";
        }
        os << "} ";
        _intString = os.str();
        return _intString.c_str();
    }
};

int main()
{
    int someInts[] {1,2,3,4,5};
    DynIntegers x(someInts, 5);
    std::cout << x <<std::endl;
    return 0;
}
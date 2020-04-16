#include <iostream>
#include <sstream>
#include <string>

class DynIntegers
{
private:
    int* _ints {NULL};
    size_t _len {0};
    std::string _intString {""};
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

        std::ostringstream os;
        os << "{ ";
        if (_ints != NULL)
        {
            for (size_t i = 0; i < _len; ++i)
            {
                os << _ints[i] << ", ";
            }
        }
        os << "} ";
        _intString = os.str();

        std::cout << "constructor called with " << *this << std::endl;
    }

    DynIntegers(const DynIntegers &cpySrc)
    {
        std::cout << "Copy constructor copies" << cpySrc << std::endl;
        if (cpySrc._ints != NULL)
        {
            _len = cpySrc._len;
            _ints = new int[_len];
            for(size_t i = 0; i < _len; ++i)
            {
                _ints[i] = cpySrc._ints[i];
            }
        }
        else _ints = NULL;
    }

    DynIntegers& operator=(const DynIntegers &cpySrc)
    {
        std::cout << "Copy assignment op. copies" << cpySrc << std::endl;
        if (this != &cpySrc && cpySrc._ints != NULL)
        {
            _len = cpySrc._len;
            _ints = new int[_len];
            for(size_t i = 0; i < _len; ++i)
            {
                _ints[i] = cpySrc._ints[i];
            }
            _intString = cpySrc._intString;
        }
        else _ints = NULL;
        return *this;
    }

    DynIntegers(DynIntegers &&mvSrc)
    {
        std::cout << "Move constructor moves" << mvSrc << std::endl;
        if (mvSrc._ints != NULL)
        {
            _len = mvSrc._len;
            _ints = mvSrc._ints;
            mvSrc._len = 0;
            mvSrc._ints = NULL;
            mvSrc._intString = "";
        }
    }

    DynIntegers& operator=(DynIntegers &&mvSrc)
    {
        std::cout << "Move assignment op moves" << mvSrc << std::endl;
        if (mvSrc != *this && mvSrc._ints != NULL)
        {
            _len = mvSrc._len;
            _ints = mvSrc._ints;
            _intString = mvSrc._intString;
            mvSrc._len = 0;
            mvSrc._ints = NULL;
            mvSrc._intString = "";
        }
        return *this;
    }

    ~DynIntegers()
    {
        std::cout << "Destructor called for" << *this << std::endl;
        if (_ints != NULL) delete[] _ints;
    }

    operator const char*() const
    {
        return _intString.c_str();
    }
};

int main()
{
    int someInts[] {1,2,3,4,5};
    DynIntegers x(someInts, 5);

    int otherInts[] { 6, 7 };
    x = DynIntegers(otherInts, 2);

    return 0;
}
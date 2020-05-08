#include <iostream>
#include <string>

// This template will be ignored until it is instantiated in code
template <typename T1, typename T2>
class HoldsPair
{
public:
    HoldsPair(const T1& val1, const T2& val2): _val1(val1), _val2(val2) { }
private:
    T1 _val1;
    T2 _val2;
public:
    const T1& GetFirstValue() const;
    const T2& GetSecondValue() const;
};

// Specialization of HoldsPair for <int,int>
template<> class HoldsPair<int, int>
{
public:
    HoldsPair(const int& val1, const int& val2): _val1(val1), _val2(val2) { }
private:
    int _val1;
    int _val2;
    std::string random;
public:
    const int & GetFirstValue() const
    {
        std::cout << "Specialized template class returning integer: " << _val1 << std::endl;
        return _val1;
    }
};

int main()
{
    // HoldsPair<double, double> myBrokenPair(3.141, .9999);
    // myBrokenPair.GetFirstValue(); // undefined reference
    
    HoldsPair<int, int> myWorkingPair(5, 10);
    myWorkingPair.GetFirstValue();
    
    return 0;
}
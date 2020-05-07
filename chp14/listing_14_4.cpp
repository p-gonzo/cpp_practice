#include <iostream>

template<typename T1=int, typename T2=T1>
class HoldsPair
{
public:
    HoldsPair(const T1& val1, const T2& val2): _val1(val1), _val2(val2) { }

private:
    T1 _val1;
    T2 _val2;

public:
    const T1& getFirstValue() const { return _val1; }
    const T2& getSecondValue() const { return _val2; }

    void setFirstValue(const T1& newVal) { _val1 = newVal; }
    void setSecondValue(const T2& newVal) { _val2 = newVal; } 
};

int main()
{

    HoldsPair<> myFirstPair(5, 10);
    std::cout << myFirstPair.getFirstValue() << " " << myFirstPair.getSecondValue() << std::endl;
    myFirstPair.setFirstValue(20);
    myFirstPair.setSecondValue(30);
    std::cout << myFirstPair.getFirstValue() << " " << myFirstPair.getSecondValue() << std::endl;


    HoldsPair<int, double> myPair(300, 10.09);
    std::cout << myPair.getFirstValue() << " " << myPair.getSecondValue() << std::endl;
    myPair.setFirstValue(55);
    myPair.setSecondValue(3.14);
    std::cout << myPair.getFirstValue() << " " << myPair.getSecondValue() << std::endl;

    HoldsPair<const char*> mySecondPair("Hello", "world!");
    std::cout << mySecondPair.getFirstValue() << " " << mySecondPair.getSecondValue() << std::endl;
    mySecondPair.setSecondValue("Colorado!");
    std::cout << mySecondPair.getFirstValue() << " " << mySecondPair.getSecondValue() << std::endl;

    return 0;
}
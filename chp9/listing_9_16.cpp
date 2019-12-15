#include <iostream>
using namespace std;

union SimpleUnion
{
    int num;
    char alphabet;
};

struct ComplexType
{
    enum DataType // Todo, what is the perpose of the word `DataType` here
    {
        Int,
        Char
    }Type;

    union Value // Todo, what is the perpose of the word `Value` here
    {
        int num;
        char alphabet;

        Value() {}
        ~Value() {}
    }value;

};

void DisplayComplexType(const ComplexType &obj)
{
    switch (obj.Type)
    {
        case ComplexType::Int:
            cout << "Union contains number: " << obj.value.num << endl;
            break;
        case ComplexType::Char:
            cout << "Union contains character: " << obj.value.alphabet << endl;
            break;
    }
}

int main()
{
    SimpleUnion u1, u2;
    u1.num = 2100;
    u2.alphabet = 'C';
    cout << "sizeof(u1) containing integer: " << sizeof(u1) << endl;
    cout << "sizeof(u2) containing character: " << sizeof(u2) << endl;

    ComplexType myData1, myData2;
    myData1.Type = ComplexType::Int;
    myData1.value.num = 2017;

    myData2.Type = ComplexType::Char;
    myData2.value.alphabet = 'X';

    DisplayComplexType(myData1);
    DisplayComplexType(myData2);

    return 0;
}
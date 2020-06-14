// #include <iostream>
// #include <string>

// #define MULTIPLY(a, b) ((a)*(b))

// template <typename T1, typename T2, typename retVal>
// retVal t_multiply(const T1 & val1, const T2 & val2)
// {
//     return val1 * val2;
// }

// template <typename T>
// void swap(T &v1, T &v2)
// {
//     T temp = v1;
//     v1 = v2;
//     v2 = temp;
// }

// template <typename T1, typename T2>
// class DoubleArrContainer
// {
// public:
//     DoubleArrContainer()
//     {
//         static_assert(sizeof(T1) != sizeof(T2), "Error, types cannot be the same");
//     }
//     template <typename GetT>
//     GetT * get()
//     {
//         if (sizeof(GetT) == sizeof(int))
//         {
//             return &(_arr1[0]);
//         }
//         else if (sizeof(GetT) == sizeof(double))
//         {
//             return &(_arr2[0]);
//         }
        
//     }
// private:
//     T1 _arr1 [10];
//     T2 _arr2 [10];
// };

// int main()
// {
//     int five {5};
//     double twoPointOne {2.1};
//     auto result = MULTIPLY(five + 1, twoPointOne);
//     std::cout << result << std::endl;

//     auto result2 = t_multiply<int, double, double>(five + 1, twoPointOne);
//     std::cout << result2 <<std::endl;

//     int ten {10};
//     std::cout << "before swapping, five is: " << five << " and ten is : " << ten << std::endl;
//     swap(five, ten);
//     std::cout << "after swapping, five is: " << five << " and ten is: " << ten << std::endl;

//     DoubleArrContainer<int, double> instance;
//     instance.get<int>();

//     return 0;
// }

#include <iostream>

template <typename T1, typename T2>
class MyClass
{
public:
    MyClass(const T1 &a, const T2 &b): _a(a), _b(b) { }
    template <typename T>
    const T GetVal() // Fails when we try to return a ptr, b/c all paths must return same type, value is cast when not ptr
    {
        if (sizeof(T) == sizeof(_a))
        {
            return _a;
        }
        else if (sizeof(T) == sizeof(_b))
        {
            return _b;
        }
    }
private:
    T1 _a;
    T2 _b;
};


int main()
{
    MyClass<int, double> instance(5, 5.5);
    std::cout << instance.GetVal<int>() << std::endl;
    std::cout << instance.GetVal<double>() << std::endl;
    return 0;
}
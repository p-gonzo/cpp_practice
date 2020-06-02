// Variadic template example

#include <iostream>
#include <string>

// base case for recursive generation?
template <typename ResType, typename ValType>
void Sum(ResType& res, const ValType& val)
{
    res += val;
    std::cout << "Base case called, result is: " << res << std::endl;
}

template <typename ResType, typename First, typename... Rest>
void Sum(ResType& res, const First& val1, const Rest&... valN)
{
    const int numArgs {sizeof...(Rest) + 1}; // add one to add val1 to Rest
    
    res += val1;
    std::cout << "Recursive case called with " << numArgs << " arguments: Result currently is: " << res << std::endl;
    return Sum(res, valN ...);
}

int main()
{
    // During compilation, the compiler actually creates
    // code for the right kind of Sum() that suits each call 
    // doing so recursively until all the arguments have 
    // been processed
    double num = 0;
    Sum(num, 3.14, 4.56, 1.1111);

    std::string str;
    Sum(str, "Hello", " world", " of", " variadic", " templates.");

    return 0;
}
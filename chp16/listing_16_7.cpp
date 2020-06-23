#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct A
{
    A(int n, char c): num(n), chr(c) { };
    int num;
    char chr;
};

int main()
{
    std::cout << "Enter a string: ";
    std::string input;
    std::cin >> input;
    
    std::string result;
    result.resize(input.size());

    std::transform(input.begin(), input.end(), result.begin(), ::toupper);

    std::cout << input << " " << result << std::endl;

    std::vector<A> aVec { A(5, 'g'), A( -2, 'r'), A(1, 'a') };

    std::sort(aVec.begin(), aVec.end(), [](A a1, A a2) { return a1.num < a2.num; });

    for (auto itr = aVec.begin(); itr < aVec.end(); ++itr)
    {
        std::cout << itr->num << ": " << itr->chr << std::endl;
    }

    return 0;
}
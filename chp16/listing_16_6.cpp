#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(const std::string & str)
{
    std::string cpy = str;
    std::reverse(cpy.begin(), cpy.end());
    return str == cpy;
}

void reverseEveryNChars(std::string & str, int N)
{
    // std::reverse(str.begin(), str.begin() + 3);
    auto pos = str.begin();
    while (pos < str.end() - N)
    {
        std::reverse(pos, pos + N); // up to but not including?
        pos += N;
    }
}

int main()
{
    std::string myStr {"Hello World!"};
    std::cout << myStr << " is a palindrome: " << isPalindrome(myStr) << std::endl;

    reverseEveryNChars(myStr, 3);
    std::cout  << myStr << std::endl;
    return 0;
}
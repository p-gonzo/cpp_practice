#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(const std::string & str)
{
    std::string cpy = str;
    std::reverse(cpy.begin(), cpy.end());
    return str == cpy;
}

int main()
{
    std::string myStr {"racecar"};
    std::cout << myStr << " is a palindrome: " << isPalindrome(myStr) << std::endl;
    return 0;
}
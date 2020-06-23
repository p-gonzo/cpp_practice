#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(const std::string & src)
{
    std::string cpy;
    cpy.resize(src.size());
    std::reverse_copy(src.begin(), src.end(), cpy.begin());
    return src == cpy;
}

int numVowels(const std::string & src)
{
    int counter { 0 };
    std::string vowels { "aeiouAEIOU"};

    for (auto ptr = src.begin(); ptr < src.end(); ++ptr)
    {
        for (auto vPtr = vowels.begin(); vPtr < vowels.end(); ++ vPtr)
        {
            if (*ptr == *vPtr) ++counter;
        }

        if (ptr + 1 == src.end() && (*ptr == 'y' || *ptr == 'Y')) ++counter;
    }
    return counter;

}

int main()
{
    std::string pal { "racecar" };
    std::cout << pal << " is a palindrome: " << (isPalindrome(pal) ? "true" : "false") << std::endl;
    std::cout << "The number of vowels in " << pal << " is " << numVowels(pal) << std::endl;

    std::string noPal { "yphily" };
    std::cout << noPal << " is a palindrome: " << (isPalindrome(noPal) ? "true" : "false") << std::endl;
    std::cout << "The number of vowels in " << noPal << " is " << numVowels(noPal) << std::endl;

}
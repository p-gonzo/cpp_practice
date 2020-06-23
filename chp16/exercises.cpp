#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

std::string everyOtherToUpper(const std::string & src)
{
    std::string res;
    res.resize(src.size());

    int i = 0;
    std::transform(src.begin(), src.end(), res.begin(), [&i](const char & c)
    {
        if (i++ % 2 == 0)
        {
            return toupper(c);
        }
        return tolower(c);
    });
    return res;
}

std::vector<size_t> findEveryCharInstance(const std::string & str, const char & target)
{
    std::vector<size_t> result;
    size_t pos = str.find(target);
    while (pos != std::string::npos)
    {
        result.push_back(pos);
        pos = str.find(target, ++pos);
    }

    return result;
}

int main()
{
    std::string pal { "racecar" };
    std::cout << pal << " is a palindrome: " << (isPalindrome(pal) ? "true" : "false") << std::endl;
    std::cout << "The number of vowels in " << pal << " is " << numVowels(pal) << std::endl;

    std::string noPal { "yphily" };
    std::cout << noPal << " is a palindrome: " << (isPalindrome(noPal) ? "true" : "false") << std::endl;
    std::cout << "The number of vowels in " << noPal << " is " << numVowels(noPal) << std::endl;

    std::string res = everyOtherToUpper(pal);
    std::cout << res << std::endl;

    std::string goodDay {"Good day String! Today is beautiful!"};
    auto occurrences = findEveryCharInstance(goodDay, 'a');
    std::for_each(occurrences.begin(), occurrences.end(), [](size_t i) {std::cout << i << std::endl;});

    return 0;
}
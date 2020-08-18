#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string input;

    std::cout << "Type a phrase: >> ";
    std::getline(std::cin, input);


    std::vector<char> chars;
    for (auto x: input)
    {
        chars.push_back(x);
    }


    bool again { true };
    while (again)
    {
        int idx { 0 };
        std::cout << "Type an index to get the char: >> ";
        std::cin >> idx;
        if (idx == -1)
        {
            again = false;
            continue;
        }
        std::cout << chars[idx] << std::endl;
    }

    again = true;
    while (again)
    {
        std::cout << "Type a char to return the value's first instance: >> ";
        char target;
        std::cin >> target;
        auto itr = std::find(chars.cbegin(), chars.cend(), target);
        if (itr == chars.cend())
        {
            std::cout << "'" << target << "' not found, exiting." << std::endl;
            again = false;
            continue;
        }
        std::cout << (std::distance(chars.cbegin(), itr)) << std::endl;
    }
    return 0;
}
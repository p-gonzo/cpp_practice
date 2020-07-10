#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string input;

    std::cout << "Type a phrase: > ";
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
        std::cout << "Type an index to get the char: > ";
        std::cin >> idx;
        std::cout << chars[idx] << std::endl;

        char againChar;
        std::cout << "c to continue, any other char to abort: > ";
        std::cin >> againChar;
        if (againChar != 'c') { again = false; }

    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


struct Dimension
{
    Dimension(int h, int w): height(h), width(w) { }
    int height;
    int width;
    std::string stringRepresentation;

    operator const char*()
    {
        std::ostringstream stream;
        stream << "Height: " << height << " Width: " << width;
        stringRepresentation = stream.str();
        return stringRepresentation.c_str();
    }
};

void addDimensionToArrayFromUserInput(std::vector<Dimension> &dims)
{
    int tempHeight;
    int tempWidth;
    std::cout << "Height: >> ";
    std::cin >> tempHeight;
    std::cout << "Width: >> ";
    std::cin >> tempWidth;
    dims.push_back(Dimension(tempHeight, tempWidth));
}

bool shouldContinue(std::string msg, char check)
{
    std::cout << msg;
    char input;
    std::cin >> input;
    return input == check;
}

int main()
{
    std::vector<Dimension> dims;
    bool addAnother {true};
    while(addAnother)
    {
        addDimensionToArrayFromUserInput(dims);
        addAnother = shouldContinue("Add another? >> ", 'y');
    }

    std::cout << dims.size() << std::endl;
    for (auto dim : dims)
    {
        std::cout << dim << ", ";
    }
    std::cout << std::endl;

    return 0;
}

// int main()
// {
//     std::string input;

//     std::cout << "Type a phrase: >> ";
//     std::getline(std::cin, input);


//     std::vector<char> chars;
//     for (auto x: input)
//     {
//         chars.push_back(x);
//     }


//     bool again { true };
//     while (again)
//     {
//         int idx { 0 };
//         std::cout << "Type an index to get the char: >> ";
//         std::cin >> idx;
//         if (idx == -1)
//         {
//             again = false;
//             continue;
//         }
//         std::cout << chars[idx] << std::endl;
//     }

//     again = true;
//     while (again)
//     {
//         std::cout << "Type a char to return the value's first instance: >> ";
//         char target;
//         std::cin >> target;
//         auto itr = std::find(chars.cbegin(), chars.cend(), target);
//         if (itr == chars.cend())
//         {
//             std::cout << "'" << target << "' not found, exiting." << std::endl;
//             again = false;
//             continue;
//         }
//         std::cout << (std::distance(chars.cbegin(), itr)) << std::endl;
//     }
//     return 0;
// }
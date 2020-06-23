#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string: ";
    std::string input;
    std::cin >> input;
    
    std::string result;
    result.resize(input.size());

    std::transform(input.begin(), input.end(), result.begin(), ::toupper);

    std::cout << input << " " << result << std::endl;

    return 0;
}
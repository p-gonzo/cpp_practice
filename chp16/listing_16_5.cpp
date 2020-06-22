#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string sample {"Hello String! Wake up to a beautiful day!"};
    std::cout << "The OG string is: " << sample << std::endl;

    sample.erase(13, 28);
    std::cout << "Truncating the second sentence: " << sample << std::endl;

    std::string::iterator i = std::find(sample.begin(), sample.end(), 'S');
    if (i != sample.end() ) sample.erase(i);
    std::cout << sample << std::endl;

    sample.erase(sample.begin(), sample.end());
    if (sample.length() == 0) std::cout << "String is now empty!" << std::endl;

    return 0;
}
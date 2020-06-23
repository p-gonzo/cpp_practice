#include <iostream>
#include <string>

int main()
{
    using namespace std::string_literals; // Note, this is needed to work

    std::string s1 = "abc\0\0def";
    std::string s2 = "abcdef";
    std::string s3 = "abc\0\0def"s;
    
    std::cout << "s1: " << s1.size() << " \"" << s1 << "\"\n";
    std::cout << "s2: " << s2.size() << " \"" << s2 << "\"\n";
    std::cout << "s3: " << s3.size() << " \"" << s3 << "\"\n"; // Note: the size of this string is bigger...

    for (auto itr = s3.begin(); itr < s3.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}
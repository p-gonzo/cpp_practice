#include <iostream>
#include <string>

int main()
{
    const char *constCStyleString = "Hello String!\0";
    std::cout << constCStyleString << std::endl;

    std::string strFromContCharPtr ( constCStyleString );
    std::cout << strFromContCharPtr << std::endl;

    std::string strFromCpy (strFromContCharPtr);
    std::cout << strFromCpy << std::endl;

    std::string strPartialCpy (constCStyleString, 5); // copies from start
    std::cout << strPartialCpy << std::endl;

    std::string otherPartialCpy (strFromCpy, 5); // coppies from end, weird.
    std::cout << otherPartialCpy << std::endl;

    std::string repeatedChars (10, 'a');
    std::cout << repeatedChars << std::endl;

    return 0;
}
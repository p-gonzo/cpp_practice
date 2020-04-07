#include <iostream>
#include <string.h>
#include <string>

class MyString
{
private:
    char* buffer;
    MyString() { }

public:

    unsigned int length {0};

    MyString(const char* input)
    {
        std::cout << "Invoked constructor" << std::endl;

        if(input != NULL)
        {
            length = strlen(input);
            buffer = new char[length +1 ];
            strcpy(buffer, input);
        }
        else buffer = NULL;
    }

    MyString(const MyString& src)
    {
        std::cout << "Invoked copy constructor" << std::endl;

        if (src.buffer != NULL)
        {
            length = strlen(src.buffer);
            buffer = new char[length + 1];
            strcpy(buffer, src.buffer);
        }
    }

    ~MyString()
    {
        std::cout << "Invoked destructor" << std::endl;
        if (buffer != NULL) delete[] buffer;
    }

    MyString& operator= (const MyString& src)
    {
        std::cout << "Invoked copy assignment operator" << std::endl;

        if (&src != this && src.buffer != NULL)
        {
            if (buffer != NULL) delete[] buffer;
            length = strlen(src.buffer);
            buffer = new char[length + 1];
            strcpy(buffer, src.buffer);
        }
    }

    const char& operator[] (int i)
    {
        if (i < length) return buffer[i];
    }

    operator const char*()
    {
        return buffer;
    }
};

int main()
{
    std::cout << "Type a statement: ";
    std::string input;
    std::getline(std::cin, input);
    
    MyString myString(input.c_str());
    MyString newString(myString);
    MyString otherString("Doesn't matter");
    otherString = newString;

    std::cout << "Using operator[] to display input:" << std::endl;
    for (int i = 0; i < otherString.length; ++i)
        std::cout << otherString[i];
    std::cout << std::endl;

    return 0;
}
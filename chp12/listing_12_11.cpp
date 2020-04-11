#include <iostream>
#include <string.h>

class MyString
{
private:
    char* buffer;

    MyString(): buffer(NULL) { std::cout << "Private default constructor called" << std::endl; }

public:
    MyString(const char* input)
    {
        std::cout << "Constructor called for: " << input << std::endl;
        if (input != NULL)
        {
            buffer = new char[strlen(input) + 1];
            strcpy(buffer, input);
        }
        else buffer = NULL;
    }

    MyString(const MyString& copySrc)
    {
        std::cout << "Copy constructor copies: " << copySrc.buffer << std::endl;
        if (copySrc.buffer != NULL)
        {
            buffer = new char[strlen(copySrc.buffer) + 1 ];
            strcpy(buffer, copySrc.buffer);
        }
        else buffer = NULL;
    }

    MyString(MyString&& moveSrc)
    {
        std::cout << "Move Constructor moves: " << moveSrc.buffer << std::endl;
        if (moveSrc.buffer != NULL)
        {
            buffer = moveSrc.buffer;
            moveSrc.buffer = NULL;
        }
    }

    MyString& operator= (const MyString& copySrc)
    {
        std::cout << "Copy assignment op. coppies: " << copySrc.buffer << std::endl;
        if (this!= &copySrc && copySrc.buffer != NULL)
        {
            if (buffer != NULL) delete[] buffer;
            buffer = new char[strlen(copySrc.buffer) + 1 ];
            strcpy(buffer, copySrc.buffer);
        }
        return *this;
    }

    MyString& operator= (MyString&& moveSrc)
    {
        std::cout << "Move assignment op. moves: " << moveSrc.buffer << std::endl;

        if (this != &moveSrc && moveSrc.buffer != NULL)
        {
            delete[] buffer;
            buffer = moveSrc.buffer;
            moveSrc.buffer = NULL;
        }
        return *this;
    }

    ~MyString()
    {
        std::cout << "Deleting " << (buffer != NULL ? buffer : "NULL") << std::endl;
        if (buffer != NULL)
        {
            delete[] buffer;
        }
    }

    int length()
    {
        if (buffer != NULL) return strlen(buffer);
        else return -1;
    }

    operator const char*()
    {
        return buffer != NULL ? buffer : "NULL";
    }

    MyString operator+ (const MyString concatSrc)
    {
        std::cout << "Operator+ called. " << std::endl;
        MyString newStr;
        if (concatSrc.buffer != NULL)
        {
            newStr.buffer = new char[length() + strlen(concatSrc.buffer) + 1];
            strcpy(newStr.buffer, buffer);
            strcat(newStr.buffer, concatSrc.buffer);
        }
        return newStr;
    }
};

MyString createString(const char* input)
{
    MyString instance(input);
    return instance;
}

int main()
{
    MyString a("Dog"); // constructor called on a
    std::cout << "---" << std::endl;
    
    a = createString("Cat"); // RvalueRef
    std::cout << "---" << std::endl;
    
    a = MyString("Hamster"); // RvalueRef
    std::cout << "---" << std::endl;
    
    MyString b = std::move(a); // Xvalue (similar to rValue, means expirering value)
    std::cout << "---" << std::endl;
    
    std::cout << b << std::endl;
    std::cout << a << std::endl;
    std::cout << "---" << std::endl;
    
    return 0;
}
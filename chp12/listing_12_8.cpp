#include <iostream>
#include <string.h>

class MyString
{
private:
    char* buffer {NULL};

public:
    MyString(const char* input)
    {
        if (input != NULL)
        {
            buffer = new char [strlen(input) + 1];
            strcpy(buffer, input);
        }
    }

    MyString(const MyString &copySource)
    {
        std::cout << "Invoked Copy Constructor" << std::endl;

        if (copySource.buffer != NULL)
        {
            buffer = new char [strlen(copySource.buffer) + 1];
            strcpy(buffer, copySource.buffer);
        }
    }

    MyString& operator= (const MyString &copySource)
    {
        std::cout << "Invoked Copy Assignment Operator" << std::endl;

        if (this != &copySource && copySource.buffer != NULL)
        {
            if (buffer!= NULL) delete[] buffer;
            buffer = new char [strlen(copySource.buffer) +1];
            strcpy(buffer, copySource.buffer);
        }

        return *this;
    }

    operator const char*()
    {
        return buffer;
    }

    ~MyString()
    {
        std::cout << "Invoked destructor" << std::endl;
        delete[] buffer;
    }

};

int main()
{
    MyString hi("Hello ");
    MyString hi2 = hi;

    MyString w("World");
    MyString q("Not important");
    q = w;
    
    std::cout << hi2 << q << std::endl;

    return 0;
}
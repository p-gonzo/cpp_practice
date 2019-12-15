#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
private:
    char* buffer;

public:
    MyString(const char* initString)
    {
        buffer = NULL;
        if (initString != NULL)
        {
            buffer = new char[strlen(initString) + 1];
            strcpy(buffer, initString);

            cout << "Buffer points to: " << (unsigned int *)buffer << endl;
        }
    }

    // Overloaded copy constructor
    MyString(const MyString &copySource)
    {
        buffer = NULL;
        if (copySource.buffer != NULL)
        {
            buffer = new char[strlen(copySource.buffer) + 1];
            strcpy(buffer, copySource.buffer);

            cout << "Buffer points to: " << (unsigned int *)buffer << endl;
        }
    }

    ~MyString()
    {
        if (buffer != NULL)
            delete [] buffer;
    }

    int GetLength() { return strlen(buffer); }
    const char* GetString() { return buffer; }
};

void UseMyString( MyString str)
{
    cout << "String buffer in SayHello is: " << str.GetLength() << " characters long." << endl;
    cout << "Buffer contains: " << str.GetString() << endl;
    return;
}

int main()
{
    MyString sayHello("Hello from String Class!");
    UseMyString(sayHello);

    return 0;
}
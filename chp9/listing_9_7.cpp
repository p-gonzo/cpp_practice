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
        if (initString != NULL)
        {
            buffer = new char[strlen(initString) + 1];
            strcpy(buffer, initString);
        }
        else
            buffer = NULL;
    }

    ~MyString()
    {
        cout << "Invoking myString destructor" << endl;
        if (buffer != NULL)
            delete[] buffer;
    }

    int getLength()
    {
        return strlen(buffer);
    }

    const char* GetString()
    {
        return buffer;
    }

};

int main()
{
    MyString sayHello("Hello from MyString class!");
    cout << "String buffer in SayHello is: " << sayHello.getLength() << " characters long." << endl;
    cout << "Buffer contains: " << sayHello.GetString() << endl;
    return 0;
}
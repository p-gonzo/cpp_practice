#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
private:
    char *buffer;
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
        // TODO - why do I need the (unsigned int * ) syntax to be able to print the location?
        cout << "Clearing memory at location " << (unsigned int *)buffer << endl;
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

void UseMyString(MyString str)
{
    cout << "String buffer in SayHello is: " << str.getLength() << " characters long." << endl;
    cout << "Buffer contains: " << str.GetString() << endl;
    return;
}

int main()
{
    MyString sayHello("Hello from MyString class!");
    // Passing to useMyString will create a shallow copy
    // The location in-memory of the buffer pointer will be the same for the local UseMyString copy and the Main copy
    // Therefore the destructor gets called twice, and a delete is called on the buffer location twice
    UseMyString(sayHello);
    return 0;
}
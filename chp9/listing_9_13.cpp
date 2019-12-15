#include <iostream>
#include <string.h>
using namespace std;

class MyString
{
private:
    char* buffer;

public:
    // Default constructor
    MyString(const char* initString)
    {
        buffer = NULL;
        if (initString != NULL)
        {
            buffer = new char[strlen(initString) + 1];
            strcpy(buffer, initString);
        }
    }

    // Copy constructor
    MyString(const MyString& copySource)
    {
        buffer = NULL;
        if (copySource.buffer != NULL)
        {
            buffer = new char[strlen(copySource.buffer) + 1];
            strcpy(buffer, copySource.buffer);
        }
    }

    ~MyString()
    {
        delete [] buffer;
    }

    int GetLength() { return strlen(buffer); }
    const char* GetString() { return buffer; }
};

class Human
{
private:
    int age;
    bool gender;
    MyString name;

public:
    Human(const MyString& InputName, int inputAge, bool gender)
        : name(InputName), age(inputAge), gender(gender) {}
    
    int GetAge() { return age; }
};

int main()
{
    MyString mansName = "Adam";
    MyString womansName = "Eve";

    // Member functions and their local variables do not playa role in defining the sizeof() a class.
    cout << "sizeof(MyString) = " << sizeof(MyString) << endl;
    cout << "sizeof(MansName) = " << sizeof(mansName) << endl;
    cout << "sizeof(womansName) = " << sizeof(womansName) << endl;

    Human firstMan(mansName, 25, true);
    Human firstWoman(womansName, 18, false);

    cout << "sizeOf(Human) = " << sizeof(Human) << endl;
    cout << "sizeof(firstMan) = " << sizeof(firstMan) << endl;
    cout << "sizeof(firstWoman) = " << sizeof(firstWoman) << endl;
}
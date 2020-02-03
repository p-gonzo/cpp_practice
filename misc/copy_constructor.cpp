#include <iostream>
#include <string.h>

class String
{
private:
    char* _buffer;
    unsigned int _size;

public:
    String() = delete;
    String(const char* _string)
    {
        _size = strlen(_string);
        _buffer = new char[_size + 1];
        memcpy(_buffer, _string, _size);
        _buffer[_size] = 0;
    }

    virtual ~String()
    {
        delete[] _buffer;
    }

    char& operator[](unsigned int index)
    {
        return _buffer[index];
    }

    String(const String& other)
    {
        _size = other._size;
        _buffer = new char[_size + 1];
        memcpy(_buffer, other._buffer, _size);
    }

    friend std::ostream& operator<<(std::ostream& stream, String& string);

};

std::ostream& operator<<(std::ostream& stream, String& string)
{
    stream << string._buffer;
    return stream;
}

int main()
{
    String string = "Hello";
    String copy = string;
    copy[1] = 'a';
    std::cout << string << std::endl;
    std::cout << copy << std::endl;
    return 0;
}
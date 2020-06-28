#include <iostream>

template <typename T>
class MyDeque
{
public:
    MyDeque()
    {
        _root[0] = new T[_blockLength];
    }

    void pushFront(T val)
    {

    }
    void pushBack(T val)
    {

    }

    T& operator[](unsigned int idx)
    {
        return *_root[idx];
    }

private:
    unsigned int _blockLength {8};
    unsigned int _size {0};
    unsigned int _capacity {_blockLength};
    T** _root = new T*[1];



};

int main()
{
    MyDeque<int> ints;
    ints.pushBack(1);
    auto x = ints[0];
    return 0;
}
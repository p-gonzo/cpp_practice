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
        unsigned int nextIdx = _size + 1;
        unsigned int rootIdx = 
    }

    T& operator[](unsigned int idx)
    {
        return *_root[idx];
    }

private:
    unsigned int _blockLength {8};
    unsigned int _rootSize {1};
    unsigned int _size {0};
    unsigned int _capacity {_blockLength};
    T* head;
    T* tail;
    T** _root = new T*[_rootSize];
};

int main()
{
    MyDeque<int> ints;
    ints.pushBack(555);
    auto x = ints[0];
    std::cout << x << std::endl;
    return 0;
}
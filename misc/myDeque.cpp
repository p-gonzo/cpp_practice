#include <iostream>

template <typename T>
class MyDeque
{
public:
    MyDeque()
    {
        _root[0] = new T[_blockLength];
        _headNode = _root[0];
        _tailNode = _root[0];
    }

    void pushFront(T val)
    {

    }
    void pushBack(T val)
    {
        // determine root and node location
        // make new node if needed
        unsigned int targetIdx = _size;
        unsigned int targetNodeIndex = (unsigned int)(targetIdx/_rootSize);
        unsigned int targetValIndex = targetIdx % _blockLength;
        _root[targetNodeIndex][targetValIndex] = val;
    }

    T& operator[](unsigned int idx)
    {
        unsigned int targetNodeIndex = (unsigned int)(idx/_rootSize);
        unsigned int targetValIndex = idx % _blockLength;
        return _root[targetNodeIndex][targetValIndex];
    }

private:
    unsigned int _blockLength {8};
    unsigned int _rootSize {1};
    
    unsigned int _size {0};
    unsigned int _capacity {_blockLength};
    
    T** _root = new T*[_rootSize];
    T* _headNode;
    T* _tailNode;

};

int main()
{
    MyDeque<int> ints;
    ints.pushBack(555);
    auto x = ints[0];
    std::cout << x << std::endl;
    // unsigned int targetNodeIndex = (unsigned int)(8 / 8);
    // std::cout << targetNodeIndex << std::endl;
    return 0;
}
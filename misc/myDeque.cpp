#include <iostream>
#include <cmath>

struct DequeLocation
{
    void set(unsigned int b, unsigned int i) { block = b; idx = i; }
    unsigned int block;
    unsigned int idx;
};

template <typename T>
class MyDeque
{
public:
    MyDeque()
    {
        _map = new T*[_numberOfBlocks];
        for (int i = 0; i < _numberOfBlocks; ++i)
        {
            _map[i] = new T[_blockLength];
        }
        _head.set(1, 0);
        _tail.set(1, 0);
    }

    unsigned int Size() const
    {
        return _size;
    }

    unsigned int Capacity() const
    {
        return _capacity;
    }

    void pushFront(T val)
    {
        _size++;
        int targetBlockIndex = _head.block;
        unsigned int targetValIndex = _head.idx - 1;

        if (targetValIndex == -1)
        {
            targetValIndex = _blockLength - 1;
            targetBlockIndex--;
        }

        if (targetBlockIndex < 0)
        {
            std::cout << "Resizing at size: " << _size << std::endl;
            unsigned int newNumberOfBlocks = _numberOfBlocks * _resizeFactor;
            
            // Update targetBlockIndex, which will update head
            targetBlockIndex = _numberOfBlocks - 1;
            
            T** newMap = new T*[newNumberOfBlocks];

            for (int i = 0; i < _numberOfBlocks; ++i)
            {
                newMap[i] = new T[_blockLength];;
            }
            for (int i = _numberOfBlocks; i < newNumberOfBlocks; ++i)
            {
                newMap[i] = _map[i - _numberOfBlocks];
            }
            delete[] _map;

            _map = newMap;
            _tail.block += _numberOfBlocks;
            _numberOfBlocks = newNumberOfBlocks;
            _capacity = _numberOfBlocks * _blockLength;

        }

        _map[targetBlockIndex][targetValIndex] = val;

        _head.block = targetBlockIndex;
        _head.idx = targetValIndex;
    }

    void pushBack(T val)
    {
        _size++;
        unsigned int targetBlockIndex = _tail.block;
        unsigned int targetValIndex = _tail.idx;

        if (targetBlockIndex > _numberOfBlocks - 1)
        {
            std::cout << "Resizing at size: " << _size << std::endl;
            unsigned int newNumberOfBlocks = _numberOfBlocks * _resizeFactor;
            T** newMap = new T*[newNumberOfBlocks];
            
            for (int i = 0; i < _numberOfBlocks; ++i)
            {
                newMap[i] = _map[i];
            }
            for (int i = _numberOfBlocks; i < newNumberOfBlocks; ++i)
            {
                newMap[i] = new T[_blockLength];
            }
            delete[] _map;

            _map = newMap;
            _numberOfBlocks = newNumberOfBlocks;
            _capacity = _numberOfBlocks * _blockLength;
        }

        // Store Value
        _map[targetBlockIndex][targetValIndex] = val;
        
        _tail.idx ++;
        if (_tail.idx == _blockLength)
        {
            _tail.idx = 0;
            _tail.block++;
        }

    }

    T& operator[](unsigned int idx)
    {
        unsigned int targetBlockIndex = _head.block;
        unsigned int targetValIndex = _head.idx + idx;
        targetBlockIndex = targetBlockIndex + floor(targetValIndex/_blockLength);
        targetValIndex = targetValIndex % _blockLength;
        return _map[targetBlockIndex][targetValIndex];
    }

    ~MyDeque()
    {
        for (int i = 0; i < _numberOfBlocks; ++i)
        {
            delete[] _map[i];
        }
        delete[] _map;
    }

private:
    unsigned int _numberOfBlocks {3};
    const unsigned int _blockLength {8};
    unsigned int _capacity {_blockLength * _numberOfBlocks};

    const int _resizeFactor { 2 };

    unsigned int _size {0};
    
    T** _map;

    DequeLocation _head;
    DequeLocation _tail;

};

int main()
{
    MyDeque<int> ints;
    for (int i = 1; i <= 20; ++i)
    {
        ints.pushBack(i * i);
    }
    for (int i = 1; i <= 20; ++i)
    {
        ints.pushFront(i * i);
    }

    for (int i = 1; i <= 20; ++i)
    {
        ints.pushBack(i * i);
    }

    for (int i = 1; i <= 20; ++i)
    {
        ints.pushFront(i * i);
    }

    std::cout << "Size: " << ints.Size() << " Capacity: " << ints.Capacity() << std::endl;

    for (int i = 0; i < ints.Size(); ++i)
    {
        std::cout << i << ": " << ints[i] << std::endl;
    }
}
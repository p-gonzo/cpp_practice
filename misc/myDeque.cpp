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
        _map = new T*[_mapSize];
        for (int i = 0; i < _mapSize; ++i)
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
    // TODO - Implement resize
    {
        _size++;
        unsigned int targetBlockIndex = _head.block;
        unsigned int targetValIndex = _head.idx - 1;

        if (targetValIndex == -1)
        {
            targetValIndex = _blockLength - 1;
            targetBlockIndex--;
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

        // Resize
        // TODO - Modify Trigger
        if (targetBlockIndex > _mapSize - 1)
        {
            // TODO - Fix resize
            std::cout << "Resizing" << std::endl;
            unsigned int newMapSize = _mapSize * 2;
            T** newMap = new T*[newMapSize];
            
            for (int i = 0; i < _mapSize; ++i)
            {
                newMap[i] = _map[i];
            }
            for (int i = _mapSize; i < newMapSize; ++i)
            {
                newMap[i] = new T[_blockLength];
            }
            delete[] _map;

            _map = newMap;
            _mapSize = newMapSize;
            _capacity = _mapSize * _blockLength;
        }
        
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
        for (int i = 0; i < _mapSize; ++i)
        {
            delete[] _map[i];
        }
        delete[] _map;
    }

// TODO - make private
    unsigned int _mapSize {3};
    const unsigned int _blockLength {8};
    unsigned int _capacity {_blockLength * _mapSize};

    // increase capacity by 2, after 80% of capacity is reached
    const double _maxCapacity { 0.8 };
    const int _resizeFactor { 2 };

    unsigned int _size {0};
    
    T** _map;

    DequeLocation _head;
    DequeLocation _tail;

};

int main()
{
    MyDeque<int> ints;
    for (int i = 1; i < 11; ++i)
    {
        ints.pushBack(i * i);
    }
    ints.pushFront(555);

    std::cout << "Size: " << ints.Size() << " Capacity: " << ints.Capacity() << std::endl;
    std::cout << "head: " << ints._head.block << " " << ints._head.idx << " tail: " << ints._tail.block << " " << ints._tail.idx << std::endl;

    for (int i = 0; i < ints.Size(); ++i)
    {
        std::cout << ints[i] << std::endl;
    }
}
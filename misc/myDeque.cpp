#include <iostream>
#include <cmath>

template <typename T>
class MyDeque
{
public:
    MyDeque()
    {
        _map[0] = new T[_blockLength];
        _headBlock = _map[0];
        _tailBlock = _map[0];
    }

    void pushFront(T val)
    {
        

    }
    void pushBack(T val)
    {
        unsigned int targetIdx = _size++;
        unsigned int targetBlockIndex = floor(targetIdx/_blockLength);
        unsigned int targetValIndex = targetIdx % _blockLength;

        if (targetBlockIndex > _mapSize - 1)
        {
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
        
        std::cout << targetBlockIndex << " " << targetValIndex << std::endl;
        _map[targetBlockIndex][targetValIndex] = val;
    }

    T& operator[](unsigned int idx)
    {
        unsigned int targetBlockIndex = floor(idx/_blockLength);
        unsigned int targetValIndex = idx % _blockLength;
        return _map[targetBlockIndex][targetValIndex];
    }

private:
    unsigned int _blockLength {8};
    unsigned int _mapSize {1};
    
    unsigned int _size {0};
    unsigned int _capacity {_blockLength};
    
    T** _map = new T*[_mapSize];
    T* _headBlock;
    T* _tailBlock;

};

int main()
{
    MyDeque<int> ints;
    for (int i = 1; i < 11; ++i)
    {
        ints.pushBack(i * i);
        std::cout << ints[i - 1] << std::endl;
    }
}
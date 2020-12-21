#include <iostream>
#include <initializer_list>

template <typename T>
class MyKontainer
{
public:
    MyKontainer()
    {
        _data = new T[_capacity];
    }

    MyKontainer(std::initializer_list<T> init)
    {
        _size = init.size();
        _capacity = _size * 2;
        _data = new T[_capacity];
        size_t i = 0;
        for (auto itr = init.begin(); itr != init.end(); ++itr)
        {
            _data[i] = *itr;
            ++i;
        }
    }

    ~MyKontainer()
    {
        delete[] _data;
    }

    size_t size() { return _size;}
    size_t capacity() { return _capacity; }

    T operator[](const int i)
    {
        return _data[i];
    }

    void push(const T val)
    {
        _data[_size++] = val;
        if (_size == _capacity) { grow(); }
    }

    template<typename... Args>
    void push(T first, Args... args)
    {
        push(first);
        push(args...);
    }

    T pop() { /* TODO - implement me*/}

private:
    T* _data;
    size_t _size {10};
    size_t _capacity {_size * 2};

    void grow()
    {
        _capacity *= 2;
        T* newData = new T[_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
    }

    void shrink() {/* TODO - implement me*/}

};

int main()
{
    MyKontainer<int> k {1,2,3,4,5};
    k.push(6);
    k.push(7);
    k.push(8,9,10,11);
    for (int i = 0; i < k.size(); ++i)
    {
        std::cout << k[i] << std::endl;
    }
    std::cout << "the capacity is: " << k.capacity() << std::endl;
    return 0;
}


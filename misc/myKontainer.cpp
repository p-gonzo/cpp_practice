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

    size_t size() const { return _size;}
    size_t capacity() const { return _capacity; }

    const T& operator[](const size_t i) const
    {
        return _data[i];
    }

    T& operator[](const size_t i)
    {
        return _data[i];
    }

    void push(const T &val)
    {
        if (_size == _capacity) { ReAlloc(_capacity * 2); }
        _data[_size++] = val;
    }

    void push(T &&val)
    {
        if (_size == _capacity) { ReAlloc(_capacity * 2); }
        _data[_size++] = std::move(val);
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
    size_t _size {1};
    size_t _capacity {_size * 2};

    void ReAlloc(const size_t newCapacity)
    {
        T* newBlock = new T[newCapacity];
        for (size_t i = 0; i < _size; ++i)
        {
            newBlock[i] = _data[i];
        }
        delete[] _data;
        _data = newBlock;
        _capacity = newCapacity;
    }
};

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;
    Vector3() { std::cout << "ctor 1" << std::endl; }
    Vector3(const float scalar): x(scalar), y(scalar), z(scalar)
    {
        std::cout << "ctor 2" << std::endl;
    }
    Vector3(const float x, const float y, const float z): x(x), y(y), z(z)
    {
        std::cout << "ctor 3" << std::endl;
    }

    Vector3(const Vector3 &other): x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copy" << std::endl;
    }
    Vector3(Vector3 &&other): x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Move" << std::endl;
    }
    ~Vector3()
    {
        std::cout << "Destroy" << std::endl;
    }

    Vector3& operator=(const Vector3 &other)
    {
        std::cout << "Copy" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(Vector3 &&other)
    {
        std::cout << "Copy" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};

template <typename T>
void printKontainer(const MyKontainer<T> &k)
{
    for (size_t i = 0; i < k.size(); ++i)
    {
        std::cout << k[i] << std::endl;
        std::cout << "---" << std::endl;
    }
}

template <>
void printKontainer(const MyKontainer<Vector3> &k)
{
    for (size_t i = 0; i < k.size(); ++i)
    {
        std::cout << k[i].x << " " << k[i].y << " " << k[i].z << std::endl;
        std::cout << "---" << std::endl;
    }
}


int main()
{
    // MyKontainer<Vector3> k {Vector3(1), Vector3(2, 3, 4)};
    // MyKontainer<Vector3> k {Vector3()};
    MyKontainer<Vector3> k;
    // Vector3();
    k.push(Vector3());
    // k.push(Vector3(9, 9, 9));
    // k.push(Vector3(), Vector3());
    // printKontainer(k);
    // std::cout << "the capacity is: " << k.capacity() << std::endl;
    return 0;
}


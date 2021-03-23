#include <string>
#include <iostream>

template <typename T>
class MyKlass
{
public:
    MyKlass()
    {
        std::cout << "default ctor" << std::endl;
    }
    MyKlass(const T &thing)
    {
        std::cout << "ctor" << std::endl;
        thing_ = thing;
    }
    MyKlass(const MyKlass &other)
    {
        std::cout << "copy" << std::endl;
        thing_ = other.thing_;
    }
    MyKlass(MyKlass &&other)
    {
        std::cout << "Moving Klass" << std::endl;
        thing_ = std::move(other.thing_);
    }
    MyKlass operator=(const MyKlass &other)
    {
        std::cout << "copy operator= on Klass" << std::endl;
        thing_ = other.thing_;
        return *this;
    }
    MyKlass operator=(MyKlass &&other)
    {
        std::cout << "move operator= on Klass" << std::endl;
        thing_ = other.thing_;
        return *this;
    }
    ~MyKlass() {std::cout << "Destory Klass" << std::endl;}
private:
    T thing_;
};

template <typename T>
class MyKontainer
{
public:
    explicit MyKontainer(T &&r_val_ref)
    {
        std::cout << "moving Kontainer" << std::endl;
        val_ = std::move(r_val_ref);
    }
    explicit MyKontainer(const T &ref)
    {
        std::cout << "copying" << std::endl;
        val_ = ref;
    }
    ~MyKontainer() {std::cout << "Destory Kontainer" << std::endl;}
private:
    T val_;
};

using MyStringKlass = MyKlass<std::string>;

int main()
{
    MyKontainer<MyStringKlass>(MyStringKlass("Hello"));
    return 0;
}
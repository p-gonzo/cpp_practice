#include <iostream>
#include <string>

template <typename T>
class UniquePointer
{

private:
    T *_ptr;
public:
    UniquePointer(T* src)
    {
        _ptr = src;
    }

    ~UniquePointer()
    {
        delete _ptr;
    }

    T* operator->() { return _ptr; }

};

class Human
{
private:
    int age;
    std::string name;

public:
    Human(int _age, std::string _name) :age(_age), name(_name) {}
    Human(Human &copySource)
    {
        age = copySource.age;
        name = copySource.name;
    }

    ~Human()
    {
        std::cout << name << " says, 'Goodbye, cruel world!'" << std::endl;
    }

    void SetName(std::string _name)
    {
        name = _name;
    }


    void Greet()
    {
        std::cout << "Hi!  I'm " << name << " and I'm " << age << " years old." << std::endl;
    }
};

int main()
{
    Human man(31, "Phil");
    Human *clone = new Human(man);
    clone->SetName("Al");
    
    man.Greet();
    clone->Greet();
    (*clone).Greet();

    std::cout << &man << std::endl;

    delete clone;

    {
        UniquePointer<Human>(new Human(29, "Bill"));
    }

    auto womanPtr = UniquePointer<Human>(new Human(29, "Alex"));
    womanPtr->Greet();
    return 0;
}


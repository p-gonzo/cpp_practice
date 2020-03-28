# CPP Practice Exercises
Based off of Sam's Teach Yourself CPP Eighth Edition

## About:
- Compiled with C++17 Standard

## TODO:
- Implement `move constructor` (p. 245)
- Study different uses of the `static` keyword (p.247)

## Notes:

#### Virtual Keyword:
- A function declared virtual means that an existing overriding function in a derived class is invoked.
- A virtual destructor is needed on a base class to ensure the derived class destructor gets called
- Virtual functions create a hidden pointer to a Virtual Function Table (VFT) on the classes that use them
    - The sizeof an instance is larger with a class that implements a VFT
- You can create an Abstract Base Class (ABC) with the following syntax:

```cpp
class AbstractBase
{
public:
    virtual void DoSomething() = 0;
};

class Derived: public AbstractBase
{
public:
    void DoSomething() { cout << "Implement virtual function"  endl; }
};
```

- An ABC can never be instantiated directly and needs to have the Derived class supply an implementation for the virtual function
- An inheritance relationship declared using the virtual keyword between classes `Derived1` and `Derived2` that inherits from class `Base` means that another class `Derived3` that inherits from `Derived1` and `Derived2` still results in the creation of only one instance of `Base` during the instantiation of `Derived3`.


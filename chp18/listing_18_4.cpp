#include <list>
#include <iostream>

template<typename T>
void DisplayContents(const T& container)
{
    for (auto elem: container) { std::cout << elem << std::endl; }
    std::cout << std::endl;
}

int main()
{
    std::list<int> ints { 0, 1, 2, 3, 4, 5 };
    auto val = ints.insert(ints.begin(), -1);
    
    while (val != ints.end())
    {
        std::cout << *val << std::endl;
        ++val;
    }

    while (ints.size() > 0)
    {
        ints.erase(ints.begin());
        DisplayContents(ints);
    }
    return 0;
}
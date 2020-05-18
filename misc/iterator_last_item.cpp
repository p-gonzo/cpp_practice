#include <iostream>
#include <list>

int main()
{   
    std::list<int> ints { 5, 10, 15, 20, 25 };
    for (auto ptr = ints.begin(); ptr != ints.end(); ++ptr)
    {
        std::cout << *ptr;
        if (std::next(ptr) != ints.end())
        {
            std::cout << " AND ";
        }
    }
    std::cout << std::endl;
    return 0;
}
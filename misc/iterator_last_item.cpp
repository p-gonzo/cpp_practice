#include <iostream>
#include <list>

int main()
{   
    int five = 5;
    int ten = 10;
    int fifteen = 15;
    int twenty = 20;
    int twentyFive = 25;
    std::list<int> ints { five, ten, fifteen, twenty, twentyFive };
    std::list<int>::iterator ptr;
    for (ptr = ints.begin(); ptr != ints.end(); ++ptr)
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
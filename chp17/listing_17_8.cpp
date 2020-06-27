#include <algorithm>
#include <deque>
#include <iostream>

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes" << std::endl;
    return malloc(size);
}


void displayDeque(const std::deque<int> & ints)
{
    for(int i: ints) std::cout << i <<  " ";
    std::cout << std::endl;
}

int main()
{
    std::deque<int> ints {3, 4, 5};
    displayDeque(ints);
    
    for (int i = 2; i > -1; --i)
    {
        ints.push_front(i);
    }
    displayDeque(ints);

    for (int i = 6; i < 10; ++i)
    {
        ints.push_back(i);
    }
    displayDeque(ints);
    
    return 0;
}
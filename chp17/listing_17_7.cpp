#include <iostream>
#include <vector>

void displaySizeAndCapacity(const std::vector<int> & ints)
{
    std::cout << "Size: " << ints.size() << " Capacity: " << ints.capacity() << std::endl;
}

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes" << std::endl;
    return malloc(size);
}

int main()
{
    
    std::vector<int> ints{ 1, 2, 3, 4, 5 };
    displaySizeAndCapacity(ints);

    ints.push_back(6);
    displaySizeAndCapacity(ints);

    ints.push_back(7);
    displaySizeAndCapacity(ints);

    ints.push_back(8);
    displaySizeAndCapacity(ints);

    ints.push_back(9);
    displaySizeAndCapacity(ints);

    ints.push_back(10);
    displaySizeAndCapacity(ints);

    ints.push_back(11);
    displaySizeAndCapacity(ints);

    return 0;
}
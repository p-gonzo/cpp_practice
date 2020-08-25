#include <list>
#include <iostream>
#include <vector>

template <typename T>
void DisplayContentsOfItr(const T& container)
{
    for (auto elem: container)
        std::cout << elem << std::endl;
}

int main()
{
    std::list<int> ints {-101, 42};
    std::vector<int> Vints(ints.cbegin(), ints.cend());
    ints.push_front(20);
    ints.push_front(5);
    ints.push_back(31);
    ints.push_back(29);
    DisplayContentsOfItr(ints);
    std::cout << std::endl;
    DisplayContentsOfItr(Vints);
    return 0;
}
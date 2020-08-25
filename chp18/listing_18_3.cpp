#include <list>
#include <iostream>

template <typename T>
void DisplayItr(const T& itr)
{
    for (auto &item: itr) std::cout << item << std::endl;
    std::cout << std::endl;
}

int main()
{
    using IntList = std::list<int>;

    IntList ints;
    ints.insert(ints.begin(), 2);
    ints.insert(ints.begin(), 1);
    ints.insert(ints.end(), 3);
    DisplayItr(ints);

    IntList ints2;
    ints2.insert(ints2.begin(), 4, 0);
    DisplayItr(ints2);

    IntList ints3;
    ints3.insert(ints3.begin(), ints.cbegin(), ints.cend());
    DisplayItr(ints3);
    ints3.insert(ints3.end(), ints2.cbegin(), ints2.cend());
    DisplayItr(ints3);

    return 0;
}
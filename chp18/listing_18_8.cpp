#include <algorithm>
#include <forward_list>
#include <iostream>

template <typename T>
void DisplayContents(const T &container)
{
    std::cout << "---" << std::endl;
    for (auto itr = container.cbegin(); itr != container.cend(); ++itr)
        std::cout << *itr << std::endl;
}

int main()
{
    std::forward_list<int> fw{3,4,2,2,0};
    fw.push_front(1);
    DisplayContents(fw);

    fw.remove(2);
    fw.sort();
    DisplayContents(fw);

    std::forward_list<bool> isEven(4, false); // forward_list does not implement a size method
    std::transform(fw.begin(), fw.end(), isEven.begin(), [](const int &val) { return val % 2 == 0;});
    DisplayContents(isEven);
    return 0;
}
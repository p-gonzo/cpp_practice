#include <vector>
#include <iostream>
#include <string>
#include <functional>

template <typename IteratorType>
using ItemType = typename std::iterator_traits<typename IteratorType::iterator>::value_type;

/* Helper Funcs*/

template <typename IteratorType>
void ForEach(IteratorType &items, std::function<void(ItemType<IteratorType> &item)> forEachCb)
{
    for (typename IteratorType::iterator ptr = items.begin(); ptr != items.end(); ++ptr)
        forEachCb(*ptr);
}

int main()
{
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    std::string word { "Hello" };

    ForEach<std::vector<int>>(nums, [](int &num) { std::cout << num << std::endl; });
    ForEach<std::string>(word,[](char &letter) { std::cout << letter << std::endl; });
    return 0;
}
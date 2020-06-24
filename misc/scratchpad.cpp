#include <assert.h>
#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <map>
#include <set>


template <typename IteratorType>
using ItemType = typename std::iterator_traits<typename IteratorType::iterator>::value_type;

template <typename IteratorType>
void for_each(IteratorType &items, std::function<void(ItemType<IteratorType> const &item)> forEachCb)
{
    for (typename IteratorType::iterator ptr = items.begin(); ptr != items.end(); ++ptr)
        forEachCb(*ptr);
}

template <typename IteratorType, typename ReturnType>
ReturnType transform_container(IteratorType &items, std::function<ItemType<ReturnType>(ItemType<IteratorType> const &item)> mapCb)
{
    ReturnType mappedIterator;
    for_each<IteratorType>(items, [&mappedIterator, &mapCb](auto &item) { mappedIterator.insert(mappedIterator.end(), mapCb(item)); });
    return mappedIterator;
}

int main()
{
    std::vector<int> vi{ 1, 2, 3, 4, 5 };
    auto vs = transform_container<std::vector<int>, std::vector<std::string>>(vi, [](int i){return std::to_string(i);});
    assert(vs == std::vector<std::string>({"1", "2", "3", "4", "5"}));

    std::set<int> si{ 5, 10, 15 };
    auto sd = transform_container<std::set<int>, std::set<double>>(si, [] (int i) { return i / 2.; }); 
    assert(sd == std::set<double>({5/2., 10/2., 15/2.}));

    return 0;
}
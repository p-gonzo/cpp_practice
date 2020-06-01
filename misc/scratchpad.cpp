#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <map>

template <typename IteratorType>
using ItemType = typename std::iterator_traits<typename IteratorType::iterator>::value_type;

/* Helper Funcs*/

template <typename IteratorType>
void ForEach(IteratorType &items, std::function<void(ItemType<IteratorType> &item)> forEachCb)
{
    for (typename IteratorType::iterator ptr = items.begin(); ptr != items.end(); ++ptr)
        forEachCb(*ptr);
}

template <typename IteratorType>
IteratorType Filter(IteratorType &items, std::function<bool(ItemType<IteratorType> &item)> filterCb)
{
    IteratorType filteredIterator;
    ForEach<IteratorType>(items, [&filteredIterator, &filterCb](auto &item) { if (filterCb(item)) filteredIterator.push_back(item); });
    return filteredIterator;
}

template <typename IteratorType>
IteratorType Map(IteratorType &items, std::function<ItemType<IteratorType>(ItemType<IteratorType> &item)> mapCb)
{
    IteratorType mappedIterator;
    ForEach<IteratorType>(items, [&mappedIterator, &mapCb](auto &item) { mappedIterator.push_back(mapCb(item)); });
    return mappedIterator;
}

template <typename IteratorType, typename MemoType>
MemoType Reduce(IteratorType &items, std::function<MemoType(ItemType<IteratorType> &item, MemoType &memo)> reduceCb, const MemoType &start)
{
    MemoType memo = start;
    ForEach<IteratorType>(items, [&memo, &reduceCb](auto &item) { memo = reduceCb(item, memo); });
    return memo;
}

int main()
{
    std::string word {"hello"};
    std::map<int,char> items {std::pair<int, char>(5, 'a'), std::pair<int, char>(6, 'b'), std::pair<int, char>(7, 'c')};
    ForEach<std::map<int,char>>(items, [](std::pair<int,char> pair){ std::cout << pair.first << ": " << pair.second << std::endl; } );
    // ForEach<std::string>(word, [](char& chr) { std::cout << chr << std::endl;});
    return 0;
}
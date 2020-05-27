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

template <typename T>
void print(T &item)
{
    std::cout << item << std::endl;
}

/* Filter, Map, Reduce */

template <typename IteratorType>
IteratorType Filter(IteratorType &items, std::function<bool(ItemType<IteratorType> &item)> filterCb)
{
    IteratorType filteredIterator;
    ForEach<IteratorType>(items, [&filteredIterator, &filterCb](auto &item) { if (filterCb(item)) filteredIterator.emplace_back(item); });
    return filteredIterator;
}

/* Filter Function template specialization for std::string*/
template <>
std::string Filter<std::string>(std::string &items, std::function<bool(char &item)> filterCb)
{
    std::string filteredString;
    ForEach<std::string>(items, [&filteredString, &filterCb](char &item) { if (filterCb(item)) filteredString += item; });
    return filteredString;
}

template <typename IteratorType>
IteratorType Map(IteratorType &items, std::function<ItemType<IteratorType>(ItemType<IteratorType> &item)> mapCb)
{
    IteratorType mappedIterator;
    ForEach<IteratorType>(items, [&mappedIterator, &mapCb](auto &item) { mappedIterator.emplace_back(mapCb(item)); });
    return mappedIterator;
}

/* Map Function template specialization for std::string*/
template <>
std::string Map<std::string>(std::string &items, std::function<char(char &item)> mapCb)
{
    std::string mappedString;
    ForEach<std::string>(items, [&mappedString, &mapCb](char &item) {  mappedString += mapCb(item); });
    return mappedString;
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
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    std::string word { "Hello" };

    ForEach<std::vector<int>>(nums, print<int>);
    
    std::cout << std::endl;
    ForEach<std::string>(word, print<char>);

    std::cout << std::endl;
    auto evens = Filter<std::vector<int>>(nums, [](int &num) { return num % 2 == 0; });
    ForEach<std::vector<int>>(evens, print<int>);

    std::cout << std::endl;
    auto word2 = Filter<std::string>(word, [](char &chr) { return chr != 'H' && chr != 'o'; });
    ForEach<std::string>(word2, print<char>);

    std::cout << std::endl;
    auto mappedVec = Map<std::vector<int>>(nums, [](int &num) { return num * num; });
    ForEach<std::vector<int>>(mappedVec, print<int>);

    std::cout << std::endl;
    auto mappedWord = Map<std::string>(word, [](char &chr) { return static_cast<char>(chr + 1); });
    ForEach<std::string>(mappedWord, print<char>);

    std::cout << std::endl;
    int reducedInt = Reduce<std::vector<int>, int>(nums, [](int &num1, int&num2) { return num1 + num2; }, 0);
    std::cout << reducedInt << std::endl;

    std::cout << std::endl;
    auto wordInts = Reduce<std::string, std::vector<int>>(word, [](char &item, std::vector<int>& memo)
    {
        memo.emplace_back(static_cast<int>(item));
        return memo;
    }, std::vector<int> { });
    ForEach<std::vector<int>>(wordInts, print<int>);

    return 0;
}
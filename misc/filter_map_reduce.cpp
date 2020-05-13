#include <vector>
#include <iostream>
#include <string>
#include <functional>

/* Helper Funcs*/

template <typename IteratorType>
void ForEach(IteratorType &items, std::function<void(typename std::iterator_traits<typename IteratorType::iterator>::value_type &item)> forEachCb)
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
IteratorType Filter(IteratorType &items, std::function<bool(typename std::iterator_traits<typename IteratorType::iterator>::value_type &item)> filterCb)
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
IteratorType Map(IteratorType &items, std::function<typename std::iterator_traits<typename IteratorType::iterator>::value_type(typename std::iterator_traits<typename IteratorType::iterator>::value_type &item)> mapCb)
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

// template<typename T, typename T2>
// T2 Reduce(std::vector<T> &items, std::function<T2(T &item, T2 &memo)> reduceCb, const T2 &start)
// {
//     T2 memo = start;
//     ForEach<T>(items, [&memo, &reduceCb](T &item) { memo = reduceCb(item, memo); });
//     return memo;
// }



int main()
{
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    std::vector<char> chars { 'a', 'b', 'c', 'd', 'e'};
    std::string word { "Hello" };

    ForEach<std::vector<int>>(nums, print<int>);
    
    std::cout << std::endl;
    ForEach<std::string>(word, print<char>);

    std::cout << std::endl;
    std::vector<int> evens = Filter<std::vector<int>>(nums, [](int &num) { return num % 2 == 0; });
    ForEach<std::vector<int>>(evens, print<int>);

    std::cout << std::endl;
    std::string word2 = Filter<std::string>(word, [](char &chr) { return chr != 'H' && chr != 'o'; });
    ForEach<std::string>(word2, print<char>);

    std::cout << std::endl;
    auto mappedVec = Map<std::vector<int>>(nums, [](int &num) { return num * num; });
    ForEach<std::vector<int>>(mappedVec, print<int>);

    // std::cout << std::endl;
    // int reducedInt = Reduce<int, int>(nums, [](int &num1, int&num2) { return num1 + num2; }, 0);
    // std::cout << reducedInt << std::endl;

    // std::cout << std::endl;
    // std::string reducedChars = Reduce<char, std::string>(chars, [](char &item, std::string& memo) { return memo + item + " "; }, "");
    // std::cout << reducedChars << std::endl;

    return 0;
}
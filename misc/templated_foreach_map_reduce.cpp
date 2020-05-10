#include <vector>
#include <iostream>
#include <string>
#include <functional>

/* Helper Funcs*/

template <typename T>
void ForEach(std::vector<T> &items, std::function<void(T &item)> forEachCb)
{
    for (T item: items)
        forEachCb(item);
}

template <typename T>
void print(T &item)
{
    std::cout << item << std::endl;
}

/* Filter, Map, Reduce */

template <typename T>
std::vector<T> Filter(std::vector<T> &items, std::function<bool(T &item)> filterCb)
{
    std::vector<T> filteredVec;
    ForEach<T>(items, [&filteredVec, &filterCb](T &item) { if (filterCb(item)) filteredVec.emplace_back(item); });
    return filteredVec;
}

template <typename T, typename T2>
std::vector<T2> Map(std::vector<T> &items, std::function<T2(T &item)> mapCb)
{
    std::vector<T2> mappedVec;
    ForEach<T>(items, [&mappedVec, &mapCb](T &item) { mappedVec.emplace_back(mapCb(item)); });
    return mappedVec;
}

template<typename T, typename T2>
T2 Reduce(std::vector<T> &items, std::function<T2(T &item, T2 &memo)> reduceCb, const T2 &start)
{
    T2 memo = start;
    ForEach<T>(items, [&memo, &reduceCb](T &item) { memo = reduceCb(item, memo); });
    return memo;
}



int main()
{
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    std::vector<char> chars { 'a', 'b', 'c', 'd', 'e'};

    std::vector<int> evens = Filter<int>(nums, [](int &num) { return num % 2 == 0; });
    ForEach<int>(evens, print<int>);

    std::cout << std::endl;
    auto mappedVec = Map<int, int>(nums, [](int &num) { return num * num; });
    ForEach<int>(mappedVec, print<int>);

    std::cout << std::endl;
    int reducedInt = Reduce<int, int>(nums, [](int &num1, int&num2) { return num1 + num2; }, 0);
    std::cout << reducedInt << std::endl;

    std::cout << std::endl;
    std::string reducedChars = Reduce<char, std::string>(chars, [](char &item, std::string& memo) { return memo + item + " "; }, "");
    std::cout << reducedChars << std::endl;

    return 0;
}
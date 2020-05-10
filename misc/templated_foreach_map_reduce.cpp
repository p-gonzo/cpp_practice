#include <vector>
#include <iostream>
#include <string>

template <typename T>
void ForEach(std::vector<T> &items, void (*cb)(T &item))
{
    for (T item: items)
        cb(item);
}

template <typename T, typename T2>
std::vector<T2> Map(std::vector<T> &items, T2 (*cb)(T &item))
{
    std::vector<T2> mappedVec;
    for (T item: items)
        mappedVec.emplace_back(cb(item));
    return mappedVec;
}

template<typename T, typename T2>
T2 Reduce(std::vector<T> &items, T2 (*cb)(T &item, T2 &memo), const T2 &start)
{

    T2 memo = start;
    for (T item: items)
        memo = cb(item, memo);
    return memo;
}

template <typename T>
void print(T &item)
{
    std::cout << item << std::endl;
}



int main()
{
    std::vector<int> nums { 1, 2, 3, 4, 5 };
    std::vector<char> chars { 'a', 'b', 'c', 'd', 'e'};

    ForEach<int>(nums, print<int>);
    
    std::cout << std::endl;
    ForEach<char>(chars, print<char>);

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
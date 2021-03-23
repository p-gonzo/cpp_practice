#include <iostream>
#include <set>

template <typename T>
void displayContents(const T& container)
{
    for (auto item: container)
        std::cout << item << ", ";
    std::cout << "\n";
}

template <typename T>
struct SortDecending
{
    bool operator()(const T& lhs, const T& rhs) const
    {
        return (lhs > rhs);
    }
};

int main()
{
    std::set<int> setInts                              {1, 202, -30, -1, 99, 5};
    std::set<int, SortDecending<int>> decendingSetInts {1, 202, -30, -1, 99, 5};
    setInts.insert(1); // duplicate
    decendingSetInts.insert(1); // duplicate;
    displayContents(setInts);
    displayContents(decendingSetInts);

    std::multiset<int> multiSetInts;
    // Will insert ascending even though source is decending
    multiSetInts.insert(decendingSetInts.begin(), decendingSetInts.end());
    multiSetInts.insert(1); // multiset
    displayContents(multiSetInts);

    std::cout << "Number of instances of '1' in multiSetInts is: " << multiSetInts.count(1) << std::endl;
    std::cout << "Number of instances of '1' in SetInts is: " << setInts.count(1) << std::endl;
    return 0;
}
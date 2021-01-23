#include <iostream>
#include <set>

template <typename T>
struct SortDecending
{
    bool operator()(const T &lhs, const T &rhs) const
    {
        return (lhs > rhs);
    }
};

template <typename T>
void displayContents(const T &container)
{
    for (auto elem: container)
        std::cout << elem << std::endl;
    std::cout << "---\n";
}

int main()
{
    std::set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    displayContents(set);

    std::set<int, SortDecending<int>> set2;
    set2.insert(1);
    set2.insert(2);
    set2.insert(3);
    displayContents(set2);

}
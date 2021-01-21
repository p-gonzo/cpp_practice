#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::vector<int> v_ints {1,2,3};
    std::list<int> l_ints;

    for (auto itr = v_ints.end() - 1; itr >= v_ints.begin(); --itr)
    {
        l_ints.insert(l_ints.end(), *itr);
    }

    for (auto elem: l_ints)
        std::cout << elem << std::endl;
    return 0;
}

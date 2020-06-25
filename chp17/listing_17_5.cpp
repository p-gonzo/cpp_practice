#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ints { 50, 1, 987, 1001 };

    for (auto itr = ints.cbegin(); itr < ints.cend(); ++itr)
    {
        size_t idx = std::distance(ints.cbegin(), itr);
        std::cout << "Element[" << idx << "] is: " << *itr << std::endl;
    }
    return 0;
}
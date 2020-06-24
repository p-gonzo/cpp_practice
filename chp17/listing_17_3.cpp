#include <iostream>
#include <vector>

void DisplayIntVector(const std::vector<int> & vec)
{
    for (auto itr = vec.cbegin(); itr < vec.cend(); ++itr)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ints(4, 90);
    DisplayIntVector(ints);

    ints.insert(ints.begin(), 25);
    ints.insert(ints.end(), 2, 45);
    DisplayIntVector(ints);

    std::vector<int> another(2, 30);
    ints.insert(ints.begin() + 1, another.begin(), another.end());
    DisplayIntVector(ints);
    return 0;
}
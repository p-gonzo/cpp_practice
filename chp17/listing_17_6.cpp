#include <iostream>
#include <vector>

template <typename T>
void DisplayVector(const std::vector<T>& vec)
{
    for (auto itr =  vec.cbegin(); itr < vec.cend(); ++itr)
        std::cout << *itr << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> ints { 50, 1, 987, 1001 };

    while(ints.size() != 0)
    {
        DisplayVector(ints);
        ints.pop_back();
    }

    return 0;

}
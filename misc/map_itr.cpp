#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    using MyMap = std::unordered_map<std::string, int>;
    MyMap map
    {
        {"Phil", 31}, {"Alex", 29}
    };

    for (MyMap::iterator itr = map.begin(); itr != map.end(); ++itr)
    {
        auto &key = itr->first;
        auto &val = itr->second;
        std::cout << key << " = " << val << std::endl;
    }

    std::cout << std::endl;

    for (auto pair: map)
    {
        auto &key = pair.first;
        auto &val = pair.second;
        std::cout << key << " = " << val << std::endl;
    }

    std::cout << std::endl;

    for (auto [key, val]: map)
    {
        std::cout << key << " = " << val << std::endl;
    }

    char name[4] = {'p', 'h', 'i', 'l'};
    auto [p, h, i, l] = name;
    std::cout << "hello " << p << h << i << l <<std::endl;

    return 0;
}
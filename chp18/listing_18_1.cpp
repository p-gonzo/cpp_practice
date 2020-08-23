#include <algorithm>
#include <list>
#include <iostream>
#include <vector>


int main()
{
    std::list<int> intList; // empty list
    std::list<int> ten(10); // has 10 ints
    std::list<int> ten99s(10, 99); // 10 vals each with 99;
    std::list<int> cpy(ten99s); // cpy of another list
    
    std::vector<int> aVec(10, 88);
    std::list<int> fromAVec(aVec.cbegin(), aVec.cend());
    
    fromAVec.push_front(77);
    fromAVec.push_back(99);

    for (auto itr = fromAVec.cbegin(); itr != fromAVec.cend(); ++itr)
    {
        std::cout << std::distance(fromAVec.cbegin(), itr) << ": " << *itr << std::endl;
    }
    return 0;
}
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ints;
    std::vector<int> ints2 { 202, 2008, -1 };
    std::vector<int> tenInts(10);
    std::vector<int> cpy(ints2);
    std::vector<int> partial(tenInts.cbegin(), tenInts.cbegin() + 5);
    std::cout 
        << ints.size() << " "
        << ints2.size() << " "
        << tenInts.size() << " "
        << ints2.size() << " "
        << partial.size()
        << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);
    
    std::cout << "Our vec is " << ints.size() << " elements in size." << std::endl;
    std::cout << "The elems are:" << std::endl;
    for (std::vector<int>::iterator itr = ints.begin(); itr < ints.end(); ++itr)
    {
        std::cout << *itr << std::endl;
    }
    return 0;
}
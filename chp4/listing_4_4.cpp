#include <iostream>
#include <vector>

void printInfoAboutArray(std::vector<int> &arr)
{
    std::cout << "Number of ints in the array are: " << arr.size() << std::endl;
    std::cout << "And their values are: ";
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> dynArray (3);
    dynArray.assign(3, 100);

    printInfoAboutArray(dynArray);

    while (dynArray.size() < 5)
    {
        std::cout << "Enter another elemnt to insert: ";
        int newValue = 0;
        std::cin >> newValue;
        dynArray.push_back(newValue);
    }
    
    printInfoAboutArray(dynArray);
    std::cout << "The last elemet in the array is: " << dynArray[dynArray.size() - 1] << std::endl;

    return 0;
}
#include <iostream>

// We pass a REFERENCE of a pointer, so the pointer value will mutate in main
void DoSomething(int *&someNums)
{
    std::cout << someNums << std::endl;
    std::cout << *someNums << std::endl;
    std::cout << *someNums + 1 << std::endl;
    std::cout << *(someNums + 1) << std::endl;
    someNums += 2;
    std::cout << someNums << std::endl; 

}

int main()
{
    int myNums[3] {2, 4, 6};
    // DoSomething(myNums); // Todo, how might I pass a pointer ref here?

    int *myNums2 = new int[3] {1, 3, 5};
    std::cout << "myNums2 in main: " << myNums2 << std::endl;
    DoSomething(myNums2);
    std::cout << "myNums2 in main: " << myNums2 << std::endl;
    myNums2 -=2;
    delete myNums2;
    return 0;
}
#include <assert.h>
#include <iostream>
#include <string>

#define SQUARE(x) ((x) * (x))
#define PI 3.1416
#define AREA_CIRCLE(r) (PI* (SQUARE((r))) )
#define MIN(a, b) (((a) < (b) ? (a) : b))
#define MAX(a, b) (((a) > (b) ? (a) : b))

#define A_SUM(a) ((a.one) + (a.two))
#define UNSAFE_PRODUCT(x,y) (x * y)
#define SAFE_PRODUCT(x,y) ((x) * (y))

struct A
{
    A(int a, int b): one(a), two(b) { }
    int one {0};
    int two {0};
};

int main()
{
    std::cout << "Enter an int: " ;
    int num {0};
    std::cin >> num;

    std::cout << "The number squared is: " << SQUARE(num) << std::endl;
    std::cout << "The area of a circle with radius " << num << " is " << AREA_CIRCLE(num) << std::endl;

    std::cout << "Enter another int: ";
    int num2 {0};
    std::cin >> num2;

    std::cout << "The min of the two numbers is: " << MIN(num, num2) << std::endl;
    std::cout << "The max of the two numbers is: " << MAX(num, num2) << std::endl;

    A thing(num, num2);

    std::cout << "A Struct thing: " << thing.one << " " << thing.two << std::endl;
    std::cout << "The sum of the struct is " << A_SUM(thing) << std::endl;

    std::cout << MIN(MIN(3,4),5) << std::endl;
    std::cout << MIN(MIN(5,4),3) << std::endl;

    std::cout << "Result of macro UNSAFE_PRODUCT: " << UNSAFE_PRODUCT(9 + 1, 1 + 9) << std::endl; // 9 + 1 * 1 + 9 = 9 + 1 + 9 = 19
    std::cout << "Result of macro SAFE_PRODUCT: " << SAFE_PRODUCT(9 + 1, 1 + 9) << std::endl; // (9 + 1) * (1 + 9) = 10 * 10 = 100

    assert(num2 == num);
    
    return 0;
}
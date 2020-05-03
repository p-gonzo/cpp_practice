#include <iostream>
#include <string>


#define ARRAY_LENGTH 25
#define PI 3.1416
#define MY_DOUBLE double
#define FAV_WHISKEY "Woodford Reserve"

auto static constexpr num {5};

int main()
{
    int numbers [ARRAY_LENGTH] {0};
    std::cout << "Arrs len is: " << sizeof(numbers) / sizeof(int) << std::endl;
    
    std::cout << "Enter a radius: ";
    MY_DOUBLE radius {0};
    std::cin >> radius;
    std::cout << "The area of the circle is: " << PI * radius * radius << std::endl;

    std::string favoriteWhiskey {FAV_WHISKEY};
    std::cout << "My favorite whiskey is " << favoriteWhiskey << std::endl;

    return 0;
}
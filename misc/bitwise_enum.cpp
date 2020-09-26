#include <iostream>

enum SomeColors
{
   white    = (1u << 0),
   red      = (1u << 1),
   yellow   = (1u << 2),
   blue     = (1u << 3),
   green    = (1u << 4),
   orange   = (1u << 5)
};

int main()
{
    unsigned int AmericanFlag { 0 };

    for ( auto i = 0; i < 33; ++i )
    {
        if ( i == SomeColors::red || i ==  SomeColors::white || i == SomeColors::blue )
        {
            AmericanFlag |= i;
        }
    }

    std::cout << ( static_cast<bool>( AmericanFlag & SomeColors::red ) ) << std::endl;
    std::cout << ( static_cast<bool>( AmericanFlag & SomeColors::white ) ) << std::endl;
    std::cout << ( static_cast<bool>( AmericanFlag & SomeColors::blue ) ) << std::endl;
    std::cout << std::endl;
    std::cout << ( static_cast<bool>( AmericanFlag & SomeColors::yellow ) ) << std::endl;
    std::cout << ( static_cast<bool>( AmericanFlag & SomeColors::green ) ) << std::endl;
    std::cout << ( static_cast<bool>( AmericanFlag & SomeColors::orange ) ) << std::endl;

}
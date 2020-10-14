#define CATCH_CONFIG_MAIN

#include "../utils/catch.hpp"
#include <iostream>

int x = 10;

TEST_CASE("Case")
{
    int y = 10;
    GIVEN("We change x and y")
    {
        x = 5;
        y = 5;
        WHEN("We check their values we see that they change")
        {
            REQUIRE(x == 5);
            REQUIRE(y == 5);
        }
    }
    GIVEN("We're back in an outer scope")
    {
        THEN("Their values should be reverted")
        {
            // REQUIRE(x == 10);
            REQUIRE(y == 10);
        }
    }
}
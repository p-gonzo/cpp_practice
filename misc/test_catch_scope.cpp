#define CATCH_CONFIG_MAIN
#include "../utils/catch.hpp"

int x = 10; // defined outside of Catch's 

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
            REQUIRE(x == 10); // This fails b/c 'x' is defined outside of catch's scope
            REQUIRE(y == 10);
        }
    }
}
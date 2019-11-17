#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Rolls Tested", "[parseString]"){
    REQUIRE(parseString(2d6))
}
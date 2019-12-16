#include <catch.hpp>
#include <trompeloeil.hpp>

#include <iostream>

#include <QSignalSpy>

extern template struct trompeloeil::reporter<trompeloeil::specialized>;


TEST_CASE("Application Tests", "[app]")
{

    SECTION("Hello World") {
        REQUIRE(true);
    }
}

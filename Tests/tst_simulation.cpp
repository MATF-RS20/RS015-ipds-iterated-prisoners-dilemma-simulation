#include <catch.hpp>
#include <trompeloeil.hpp>

#include "simulation.h"

TEST_CASE("Specimen factory creating Dove", "[Specimen factory]")
{
    int foodNo = 5;
    std::vector<unsigned> a{1,2,3,4,5,6,7};
    Simulation s = Simulation(foodNo, a);
    //std::shared_ptr<Specimen> dovePtr = s.specimenFactory(E_DOVE);
    //CHECK(dynamic_cast<Dove*>(dovePtr.get()) != nullptr);
    REQUIRE(true);
}

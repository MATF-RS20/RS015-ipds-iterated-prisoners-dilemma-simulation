#include <catch.hpp>
#include <trompeloeil.hpp>

#include "simulation.h"

TEST_CASE("Checking if Specimen factory creates appropriate classes", "[specimenFactory]")
{
    int foodNo = 5;
    std::vector<unsigned> a{1,2,3,4,5,6,7};
    Simulation s = Simulation(foodNo, a);

    SECTION("Dove"){
        std::shared_ptr<Specimen> dovePtr = s.specimenFactory(E_DOVE);
        CHECK(dynamic_cast<Dove*>(dovePtr.get()) != nullptr);
    }

    SECTION("Hawk"){
        std::shared_ptr<Specimen> hawkPtr = s.specimenFactory(E_HAWK);
        CHECK(dynamic_cast<Hawk*>(hawkPtr.get()) != nullptr);
    }

    SECTION("Pavlov"){
        std::shared_ptr<Specimen> pavlovPtr = s.specimenFactory(E_PAVLOV);
        CHECK(dynamic_cast<Pavlov*>(pavlovPtr.get()) != nullptr);
    }

    SECTION("AllRandom"){
        std::shared_ptr<Specimen> rndPtr = s.specimenFactory(E_RANDOM);
        CHECK(dynamic_cast<AllRandom*>(rndPtr.get()) != nullptr);
    }

    SECTION("Tit-for-Tat"){
        std::shared_ptr<Specimen> tftPtr = s.specimenFactory(E_TITFORTAT);
        CHECK(dynamic_cast<TitForTat*>(tftPtr.get()) != nullptr);
    }

    SECTION("Tit-for-Two-Tats"){
        std::shared_ptr<Specimen> tfttPtr = s.specimenFactory(E_TITFORTWOTATS);
        CHECK(dynamic_cast<TitForTwoTats*>(tfttPtr.get()) != nullptr);
    }

    SECTION("Two-Tits-for-Tat"){
        std::shared_ptr<Specimen> ttftPtr = s.specimenFactory(E_TWOTITSFORTAT);
        CHECK(dynamic_cast<TwoTitsForTat*>(ttftPtr.get()) != nullptr);
    }
}

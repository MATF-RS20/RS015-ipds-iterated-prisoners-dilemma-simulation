#include "specimen.h"

#ifndef RANDOM_H
#define RANDOM_H

class AllRandom : public Specimen
{
public:
    AllRandom();
    bool isCooperating(int enemyID) override;
};

#endif // RANDOM_H

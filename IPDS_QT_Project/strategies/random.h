#include "specimen.h"

#ifndef RANDOM_H
#define RANDOM_H

class AllRandom : public Specimen
{
public:
    AllRandom();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;
};

#endif // RANDOM_H

#include "specimen.h"

#ifndef RANDOM_H
#define RANDOM_H

class Random : public Specimen
{
public:
    Random();
    bool isCooperating(int enemyID) override;
};

#endif // RANDOM_H

#include "specimen.h"

#ifndef HAWK_H
#define HAWK_H

class Hawk : public Specimen
{
public:
    Hawk();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;
};

#endif // HAWK_H

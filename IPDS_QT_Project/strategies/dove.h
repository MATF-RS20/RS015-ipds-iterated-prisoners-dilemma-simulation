#include "specimen.h"

#ifndef DOVE_H
#define DOVE_H

class Dove : public Specimen
{
public:
    Dove();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;
};

#endif // DOVE_H

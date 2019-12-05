#include "specimen.h"

#ifndef HAWK_H
#define HAWK_H

/* Dove always deflects no matter what.
 * It does not take into account previous encounters. */

class Hawk : public Specimen
{
public:
    Hawk();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;
};

#endif // HAWK_H

#include "specimen.h"

#ifndef DOVE_H
#define DOVE_H

/* Dove always cooperates with the enemy no matter what.
 * It does not take into account previous encounters. */

class Dove : public Specimen
{
public:
    Dove();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;
};

#endif // DOVE_H

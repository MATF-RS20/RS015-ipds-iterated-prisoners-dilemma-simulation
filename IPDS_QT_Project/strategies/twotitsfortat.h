#include "specimen.h"

#ifndef TWOTITSFORTAT_H
#define TWOTITSFORTAT_H

/* TwoTitsForTat is a more punishing version of TitForTat.
 * It starts by cooperating, but every time the opponent deflects,
 * TwoTitsForTat will deflect next two rounds. */

class TwoTitsForTat : public Specimen
{
public:
    TwoTitsForTat();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;

private:
    std::map<int,int> mapCooperatedCount;
};

#endif // TWOTITSFORTAT_H

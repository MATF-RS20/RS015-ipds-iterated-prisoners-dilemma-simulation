#include "specimen.h"

#ifndef TITFORTWOTATS_H
#define TITFORTWOTATS_H

/* TitForTwoTats is a more forgiving version of TitForTat.
 * It starts by cooperating and keeps cooperating until the
 * opponent deflects twice in a row. As long as oppontent's
 * last two moves were deflections, it will keep deflecting. */

class TitForTwoTats : public Specimen
{
public:
    TitForTwoTats();

    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;

private:
    std::map<int,int> mapDeflectionInARow;

};

#endif // TITFORTWOTATS_H

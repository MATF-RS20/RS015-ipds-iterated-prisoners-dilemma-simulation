#include "specimen.h"

#ifndef PAVLOV_H
#define PAVLOV_H


/*            ( FROM EOUTCOME.H )
 * A quick way to describe possible outcomes
 * of a round of prisoner's dilemma:
 ** R - Reward
 **     Both parties cooperated and get rewarded.
 ** T - Temptation Reward
 **     A deflected and B cooperated, so A gets
 **     a temptation reward.
 ** S - Sucker's Punishment
 **     A deflected and B cooperated, so B gets
 **     sucker's punishment.
 ** P - Punishment
 **     Both parties deflected and get punished. */

/* Pavlov cooperates if he got T or S last round against
 * the same oppontent. It delfects if it got R or P.
 * Essentially, if it profited from the last round (R or T)
 * it repeats the behavior, and if it lost (S or P) it changes
 * its behavior to the opposite. */

class Pavlov : public Specimen
{
public:
    Pavlov();
    bool isCooperating(int enemyID) override;
    void update(outcome res, int enemyID) override;

private:
    std::map<int,bool> rewardedOrPunished;
};

#endif // PAVLOV_H

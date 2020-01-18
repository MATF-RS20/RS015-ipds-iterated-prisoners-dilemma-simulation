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

/* Pavlov cooperates if he got P or R last round against
 * the same oppontent. It delfects if it got S or T.
 * Essentially, if it profited from the last round (R or T)
 * it repeats the behavior, and if it lost (S or P) it changes
 * its behavior to the opposite. Pavlov is also known as
 * Win-Stay Lose-Switch strategy. */

class Pavlov : public Specimen
{
public:
    Pavlov();
    bool isCooperating(int enemyID) override;

    QColor getColor() override;
    std::string getPathBase() override;
    static const QColor COLOR;
    static const QColor GRAPHCOLOR;
    static const std::string NAME;
    static const std::string IMG_PATH
    ;
private:
    std::map<int,bool> m_mapRewardedOrPunished;

    void performUpdate(outcome o, int enemyID) override;
};

#endif // PAVLOV_H

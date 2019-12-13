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
    QColor getColor() override;
    std::string getPathBase() override;

    static const QColor color;
    static const std::string imgPath;
private:
    std::map<int,int> mapCooperatedCount;
};

#endif // TWOTITSFORTAT_H

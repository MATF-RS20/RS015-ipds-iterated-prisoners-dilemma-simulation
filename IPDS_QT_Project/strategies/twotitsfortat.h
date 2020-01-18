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

    QColor getColor() override;
    std::string getPathBase() override;
    static const QColor COLOR;
    static const QColor GRAPHCOLOR;
    static const std::string NAME;
    static const std::string IMG_PATH;

private:
    std::map<int,int> m_mapCooperatedCount;

    void performUpdate(outcome o, int enemyID) override;
};

#endif // TWOTITSFORTAT_H

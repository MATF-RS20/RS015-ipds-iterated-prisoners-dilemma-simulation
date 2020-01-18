#include "specimen.h"
#include <map>

#ifndef TITFORTAT_H
#define TITFORTAT_H

/* TitForTat is a strategy that essentially copies
 * opponent's last move. It starts by cooperating, and
 * every next move it playes what the given opponent
 * played last. */

class TitForTat : public Specimen
{
public:
    TitForTat();
    bool isCooperating(int enemyID) override;

    QColor getColor() override;
    std::string getPathBase() override;
    static const QColor COLOR;
    static const QColor GRAPHCOLOR;
    static const std::string NAME;
    static const std::string IMG_PATH;

private:
    std::map<int,bool> m_mapCooperated;

    void performUpdate(outcome o, int enemyID) override;
};

#endif // TITFORTAT_H

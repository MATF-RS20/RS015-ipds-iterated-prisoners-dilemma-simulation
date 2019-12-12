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
    void update(outcome res, int enemyID) override;

    static const QColor color;
    static const std::string imgPath;
private:
    std::map<int,bool> mapCooperated;
};

#endif // TITFORTAT_H

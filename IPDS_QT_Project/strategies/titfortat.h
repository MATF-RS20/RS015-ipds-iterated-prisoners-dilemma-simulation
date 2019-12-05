#include "specimen.h"
#include <map>

#ifndef TITFORTAT_H
#define TITFORTAT_H


class TitForTat : public Specimen
{
public:
    TitForTat();
    bool isCooperating(int enemyID) override;

private:
    std::map<int,bool> mapCooperated;
};

#endif // TITFORTAT_H

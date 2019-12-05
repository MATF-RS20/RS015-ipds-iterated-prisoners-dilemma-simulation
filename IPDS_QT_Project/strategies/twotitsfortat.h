#include "specimen.h"

#ifndef TWOTITSFORTAT_H
#define TWOTITSFORTAT_H


class TwoTitsForTat : public Specimen
{
public:
    TwoTitsForTat();
    bool isCooperating(int enemyID) override;

private:
    std::map<int,bool> mapCooperated;
    bool punishing = false;
};

#endif // TWOTITSFORTAT_H

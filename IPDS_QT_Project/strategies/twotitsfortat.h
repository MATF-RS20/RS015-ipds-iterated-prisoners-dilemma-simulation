#include "specimen.h"

#ifndef TWOTITSFORTAT_H
#define TWOTITSFORTAT_H


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

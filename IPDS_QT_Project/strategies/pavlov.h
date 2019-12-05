#include "specimen.h"

#ifndef PAVLOV_H
#define PAVLOV_H


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

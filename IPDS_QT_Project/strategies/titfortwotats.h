#include "specimen.h"

#ifndef TITFORTWOTATS_H
#define TITFORTWOTATS_H


class TitForTwoTats : public Specimen
{
public:
    TitForTwoTats();

    bool isCooperating(int enemyID) override;

private:
    std::map<int,int> mapDeflectionInARow;

};

#endif // TITFORTWOTATS_H

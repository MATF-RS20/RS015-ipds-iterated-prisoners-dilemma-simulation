#ifndef HAWK_H
#define HAWK_H

#include "specimen.h"


class Hawk : public Specimen
{
public:
    Hawk();
    bool isCooperating(int enemyID) override;
};

#endif // HAWK_H

#ifndef DOVE_H
#define DOVE_H

#include "specimen.h"


class Dove : public Specimen
{
public:
    Dove();
    bool isCooperating(int enemyID) override;
};

#endif // DOVE_H

#include "specimen.h"

#include <cmath>

Specimen::Specimen() : specimenID(ID)
{
    ID++;
}

unsigned Specimen::ID = 0;

#include "specimen.h"

#include <cmath>

Specimen::Specimen() : specimenID(ID){
    ID++;
}

unsigned Specimen::ID = 0;

Specimen::Specimen(Specimen& s) : specimenID(s.ID) {}

Specimen& Specimen::operator=(Specimen& s){
    this->ID = s.ID;
    return *this;
}

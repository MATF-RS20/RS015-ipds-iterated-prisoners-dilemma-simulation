#include "dove.h"

Dove::Dove() : Specimen(Qt::GlobalColor::cyan, "TODO") {}

bool Dove::isCooperating(int){
    return true;
}

void Dove::update(outcome,int){}

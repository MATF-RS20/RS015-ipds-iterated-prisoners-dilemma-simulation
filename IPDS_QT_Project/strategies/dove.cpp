#include "dove.h"

const QColor Dove::color = Qt::GlobalColor::cyan;
const std::string Dove::imgPath = "TODO";

Dove::Dove() : Specimen() {}

bool Dove::isCooperating(int){
    return true;
}

void Dove::update(outcome,int){}

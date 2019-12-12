#include "hawk.h"

const QColor Hawk::color = Qt::GlobalColor::red;
const std::string Hawk::imgPath = "TODO";

Hawk::Hawk() : Specimen() {}

bool Hawk::isCooperating(int){
    return false;
}

void Hawk::update(outcome,int){}

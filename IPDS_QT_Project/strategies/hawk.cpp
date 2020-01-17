#include "hawk.h"
#include "estrategy.h"

const QColor Hawk::COLOR = Qt::GlobalColor::red;
const QColor Hawk::GRAPHCOLOR = QColor(255,0,0,100);
const std::string Hawk::IMG_PATH = ":/chickPics/red";

Hawk::Hawk() : Specimen() {}

bool Hawk::isCooperating(int){
    return false;
}

void Hawk::performUpdate(outcome o, int){
    calculateFood(o);
}


QColor Hawk::getColor()
{
    return this->COLOR;
}

std::string Hawk::getPathBase()
{
    return IMG_PATH;
}

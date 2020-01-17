#include "dove.h"
#include "estrategy.h"

const QColor Dove::COLOR = Qt::GlobalColor::cyan;
const QColor Dove::GRAPHCOLOR = QColor(0,255,255,50);
const std::string Dove::IMG_PATH = ":/chickPics/blue";

Dove::Dove() : Specimen() {}

bool Dove::isCooperating(int){
    return true;
}

void Dove::performUpdate(outcome o, int){
    calculateFood(o);
}

QColor Dove::getColor()
{
    return COLOR;
}

std::string Dove::getPathBase()
{
    return IMG_PATH;
}

#include "dove.h"
#include "estrategy.h"

const QColor Dove::COLOR = Qt::GlobalColor::cyan;
const std::string Dove::IMG_PATH = ":/chickPics/blue";

Dove::Dove() : Specimen() {}

bool Dove::isCooperating(int){
    return true;
}
QColor Dove::getColor()
{
    return COLOR;
}
std::string Dove::getPathBase()
{
    return IMG_PATH;
}
void Dove::update(outcome,int){}

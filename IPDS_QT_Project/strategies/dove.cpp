#include "dove.h"
#include "estrategy.h"

const QColor Dove::color = Qt::GlobalColor::cyan;
const std::string Dove::imgPath = ":/chickPics/blue";

Dove::Dove() : Specimen() {}

bool Dove::isCooperating(int){
    return true;
}
QColor Dove::getColor()
{
    return color;
}
std::string Dove::getPathBase()
{
    return imgPath;
}
void Dove::update(outcome,int){}

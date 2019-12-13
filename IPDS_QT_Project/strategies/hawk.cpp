#include "hawk.h"
#include "estrategy.h"

const QColor Hawk::color = Qt::GlobalColor::red;
const std::string Hawk::imgPath = ":/chickPics/red";

Hawk::Hawk() : Specimen() {}

bool Hawk::isCooperating(int){
    return false;
}
QColor Hawk::getColor()
{
    return this->color;
}
std::string Hawk::getPathBase()
{
    return imgPath;
}
void Hawk::update(outcome,int){}

#include "hawk.h"
#include "estrategy.h"

const QColor Hawk::COLOR = Qt::GlobalColor::red;
const std::string Hawk::IMG_PATH = ":/chickPics/red";

Hawk::Hawk() : Specimen() {}

bool Hawk::isCooperating(int){
    return false;
}
QColor Hawk::getColor()
{
    return this->COLOR;
}
std::string Hawk::getPathBase()
{
    return IMG_PATH;
}
void Hawk::update(outcome,int){}

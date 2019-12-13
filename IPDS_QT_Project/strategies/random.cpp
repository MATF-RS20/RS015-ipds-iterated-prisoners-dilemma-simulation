#include "random.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include "estrategy.h"

const QColor AllRandom::color = Qt::GlobalColor::darkRed;
const std::string AllRandom::imgPath = ":/chickPics/green";

AllRandom::AllRandom() : Specimen() {
    srand(time(NULL));
}

bool AllRandom::isCooperating(int){
    if(rand() % 2 == 0)
        return true;
    else
        return false;
}

QColor AllRandom::getColor()
{
    return this->color;
}

std::string AllRandom::getPathBase()
{
    return imgPath;
}

void AllRandom::update(outcome,int){}

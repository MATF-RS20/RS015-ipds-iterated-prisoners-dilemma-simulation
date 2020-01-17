#include "random.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include "estrategy.h"

const QColor AllRandom::COLOR = QColor(255,105,180,100);
const QColor AllRandom::GRAPHCOLOR = QColor(255,105,180,0);
const std::string AllRandom::IMG_PATH = ":/chickPics/pink";

AllRandom::AllRandom() : Specimen() {
    srand(time(NULL));
}

bool AllRandom::isCooperating(int){
    if(rand() % 2 == 0)
        return true;
    else
        return false;
}

void AllRandom::performUpdate(outcome o, int){
    calculateFood(o);
}

QColor AllRandom::getColor()
{
    return this->COLOR;
}

std::string AllRandom::getPathBase()
{
    return IMG_PATH;
}

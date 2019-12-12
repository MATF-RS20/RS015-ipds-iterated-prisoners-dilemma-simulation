#include "random.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>

const QColor AllRandom::color = Qt::GlobalColor::darkRed;
const std::string AllRandom::imgPath = "TODO";

AllRandom::AllRandom() : Specimen() {
    srand(time(NULL));
}

bool AllRandom::isCooperating(int){
    if(rand() % 2 == 0)
        return true;
    else
        return false;
}

void AllRandom::update(outcome,int){}

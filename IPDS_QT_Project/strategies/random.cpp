#include "random.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>

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

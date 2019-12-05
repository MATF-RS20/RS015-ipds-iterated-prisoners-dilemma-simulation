#include "random.h"
#include <stdlib.h> /* srand, rand */

AllRandom::AllRandom() : Specimen() {}

bool AllRandom::isCooperating(int){
    if(rand() % 2 == 0)
        return true;
    else
        return false;
}

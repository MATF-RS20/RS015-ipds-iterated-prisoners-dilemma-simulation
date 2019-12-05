#include "random.h"
#include <stdlib.h> /* srand, rand */

Random::Random() : Specimen() {}

bool isCooperating(int){
    if(rand() % 2 == 0)
        return true;
    else
        return false;
}

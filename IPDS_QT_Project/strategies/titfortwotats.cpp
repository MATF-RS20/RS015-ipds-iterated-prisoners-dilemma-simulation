#include "titfortwotats.h"

TitForTwoTats::TitForTwoTats() : Specimen() {}

bool TitForTwoTats::isCooperating(int enemyID){
    try{
        if(mapDeflectionInARow[enemyID]<2)
            return true;
        else
            return false;
    } catch (std::out_of_range){
        return true;
    }
}

#include "titfortat.h"

TitForTat::TitForTat() : Specimen() {}

bool TitForTat::isCooperating(int enemyID){
    try{
        if(mapCooperated[enemyID]==true)
            return true;
        else
            return false;
    } catch (std::out_of_range){
        return true;
    }
}

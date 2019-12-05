#include "twotitsfortat.h"

TwoTitsForTat::TwoTitsForTat() : Specimen() {}

bool TwoTitsForTat::isCooperating(int enemyID){
    try{
        if(mapCooperated[enemyID]==true){
            if(punishing){
                punishing = false;
                return false;
            }
            else
                return true;
        }
        else
            return false;
    } catch (std::out_of_range){
        return true;
    }
}

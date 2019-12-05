#include "pavlov.h"

Pavlov::Pavlov() : Specimen() {}

/*  T > R > P > S
 *  Temptation
 *      Reward
 *          Punishment
 *               Sucker */
bool Pavlov::isCooperating(int enemyID){
    try{
        if(rewardedOrPunished[enemyID]==true)
            return true;
        else
            return false;
    } catch (std::out_of_range){
        return true;
    }
}

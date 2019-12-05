#include "pavlov.h"

Pavlov::Pavlov() : Specimen() {}

bool Pavlov::isCooperating(int enemyID){
    if(rewardedOrPunished.count(enemyID)>0){
        if(rewardedOrPunished[enemyID]==true)
            return true;
        else
            return false;
    }
    else
        return true;
}

void Pavlov::update(outcome res, int enemyID){
    bool val = true;
    if(res==R || res==P){
        val = true;
    }
    else if(res==T || res==S){
        val = false;
    }

    if(rewardedOrPunished.count(enemyID)>0){
        rewardedOrPunished[enemyID]=val;
    }
    else{
        rewardedOrPunished.insert(std::pair<int,bool>(enemyID, val));
    }
}

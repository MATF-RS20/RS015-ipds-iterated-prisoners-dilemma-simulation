#include "titfortat.h"

TitForTat::TitForTat() : Specimen(Qt::GlobalColor::green, "TODO") {}

bool TitForTat::isCooperating(int enemyID){
    if(mapCooperated.count(enemyID)>0){
        if(mapCooperated[enemyID]==true)
            return true;
        else
            return false;
    }
    else
        return true;
}

void TitForTat::update(outcome res, int enemyID){
    bool cooperated = true;
    if(res==R || res==T){
        cooperated = true;
    }
    else if(res==S || res==P){
        cooperated = false;
    }

    if(mapCooperated.count(enemyID)>0){
        mapCooperated[enemyID]=cooperated;
    }
    else{
        mapCooperated.insert(std::pair<int,bool>(enemyID, cooperated));
    }
}

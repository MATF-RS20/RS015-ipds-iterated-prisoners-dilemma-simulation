#include "twotitsfortat.h"

const QColor TwoTitsForTat::color = Qt::GlobalColor::darkYellow;
const std::string TwoTitsForTat::imgPath = "TODO";

TwoTitsForTat::TwoTitsForTat() : Specimen() {}

bool TwoTitsForTat::isCooperating(int enemyID){
    if(mapCooperatedCount.count(enemyID)>0){
        if(mapCooperatedCount[enemyID]<2){
            return false;
        }
        else
            return true;
    }
    else
        return true;
}

void TwoTitsForTat::update(outcome res, int enemyID){
    bool cooperated = true;
    if(res==R || res==T){
        cooperated = true;
    }
    else if(res==S || res==P){
        cooperated = false;
    }

    if(mapCooperatedCount.count(enemyID)>0){
        if(cooperated && mapCooperatedCount[enemyID]<2)
            mapCooperatedCount[enemyID]+=1;
        else if(!cooperated){
            mapCooperatedCount[enemyID]=0;
        }
    }
    else{
        if(!cooperated)
            mapCooperatedCount.insert(std::pair<int,bool>(enemyID, 0));
    }
}

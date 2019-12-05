#include "titfortwotats.h"

TitForTwoTats::TitForTwoTats() : Specimen() {}

bool TitForTwoTats::isCooperating(int enemyID){
    if(mapDeflectionInARow.count(enemyID)>0){
        if(mapDeflectionInARow[enemyID]<2)
            return true;
        else
            return false;
    }
    else
        return true;
}

void TitForTwoTats::update(outcome res, int enemyID){
    bool cooperated = true;
    if(res==R || res==T){
        cooperated = true;
    }
    else if(res==S || res==P){
        cooperated = false;
    }

    if(mapDeflectionInARow.count(enemyID)>0){
        if(cooperated)
            mapDeflectionInARow[enemyID]=0;
        else
            mapDeflectionInARow[enemyID]+=1;
    }
    else{
        if(!cooperated)
           mapDeflectionInARow.insert(std::pair<int,bool>(enemyID, 1));
    }
}

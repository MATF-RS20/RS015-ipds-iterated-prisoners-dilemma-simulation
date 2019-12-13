#include "titfortat.h"
#include "estrategy.h"

const QColor TitForTat::color = Qt::GlobalColor::green;
const std::string TitForTat::imgPath = ":/chickPics/pink";

TitForTat::TitForTat() : Specimen() {}

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

QColor TitForTat::getColor()
{
    return this->color;
}
std::string TitForTat::getPathBase()
{
    return imgPath;
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

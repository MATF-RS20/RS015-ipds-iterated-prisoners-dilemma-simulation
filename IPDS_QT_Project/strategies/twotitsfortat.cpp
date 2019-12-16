#include "twotitsfortat.h"
#include "estrategy.h"

const QColor TwoTitsForTat::COLOR = Qt::GlobalColor::darkYellow;
const std::string TwoTitsForTat::IMG_PATH = ":/chickPics/blue3";;

TwoTitsForTat::TwoTitsForTat() : Specimen() {}

bool TwoTitsForTat::isCooperating(int enemyID){
    if(m_mapCooperatedCount.count(enemyID)>0){
        if(m_mapCooperatedCount[enemyID]<2){
            return false;
        }
        else
            return true;
    }
    else
        return true;
}

QColor TwoTitsForTat::getColor()
{
    return this->COLOR;
}
std::string TwoTitsForTat::getPathBase()
{
    return IMG_PATH;
}
void TwoTitsForTat::update(outcome res, int enemyID){
    bool cooperated = true;
    if(res==R || res==T){
        cooperated = true;
    }
    else if(res==S || res==P){
        cooperated = false;
    }

    if(m_mapCooperatedCount.count(enemyID)>0){
        if(cooperated && m_mapCooperatedCount[enemyID]<2)
            m_mapCooperatedCount[enemyID]+=1;
        else if(!cooperated){
            m_mapCooperatedCount[enemyID]=0;
        }
    }
    else{
        if(!cooperated)
            m_mapCooperatedCount.insert(std::pair<int,bool>(enemyID, 0));
    }
}

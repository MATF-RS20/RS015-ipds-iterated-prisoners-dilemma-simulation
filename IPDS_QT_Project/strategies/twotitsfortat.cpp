#include "twotitsfortat.h"
#include "estrategy.h"

const QColor TwoTitsForTat::COLOR = Qt::GlobalColor::darkYellow;
const QColor TwoTitsForTat::GRAPHCOLOR = QColor(155,135,12,0);
const std::string TwoTitsForTat::NAME = "TwoTitsForTat";
const std::string TwoTitsForTat::IMG_PATH = ":/chickPics/normal";

TwoTitsForTat::TwoTitsForTat() : Specimen() {}

bool TwoTitsForTat::isCooperating(int enemyID){
    // if it's interacted with this enemy before
    if(m_mapCooperatedCount.count(enemyID)>0){
        // if the enemy didn't cooperate
        // twice in a row, deflect
        if(m_mapCooperatedCount[enemyID]<2){
            return false;
        }
        // if the enemy cooperated twice in
        // a row, cooperate
        else
            return true;
    }
    // if it's their first encounter, cooperate
    else
        return true;
}

void TwoTitsForTat::performUpdate(outcome o, int enemyID){
    calculateFood(o);

    bool cooperated = true;
    if(o==R || o==T){
        cooperated = true;
    }
    else if(o==S || o==P){
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

QColor TwoTitsForTat::getColor()
{
    return this->COLOR;
}

std::string TwoTitsForTat::getPathBase()
{
    return IMG_PATH;
}

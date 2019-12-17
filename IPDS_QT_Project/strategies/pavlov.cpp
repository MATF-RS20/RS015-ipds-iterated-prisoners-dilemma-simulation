#include "pavlov.h"
#include "estrategy.h"

const QColor Pavlov::COLOR = Qt::GlobalColor::darkBlue;
const std::string Pavlov::IMG_PATH = ":/chickPics/blue2";


Pavlov::Pavlov() : Specimen() {}

bool Pavlov::isCooperating(int enemyID){
    if(m_mapRewardedOrPunished.count(enemyID)>0){
        if(m_mapRewardedOrPunished[enemyID]==true)
            return true;
        else
            return false;
    }
    else
        return true;
}

void Pavlov::performUpdate(outcome o, int enemyID){
    calculateFood(o);

    bool val = true;
    if(o==R || o==P){
        val = true;
    }
    else if(o==T || o==S){
        val = false;
    }

    if(m_mapRewardedOrPunished.count(enemyID)>0){
        m_mapRewardedOrPunished[enemyID]=val;
    }
    else{
        m_mapRewardedOrPunished.insert(std::pair<int,bool>(enemyID, val));
    }
}

QColor Pavlov::getColor()
{
    return this->COLOR;
}

std::string Pavlov::getPathBase()
{
    return IMG_PATH;
}

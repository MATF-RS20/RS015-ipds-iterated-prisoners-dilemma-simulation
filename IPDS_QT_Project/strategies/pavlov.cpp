#include "pavlov.h"
#include "estrategy.h"

const QColor Pavlov::COLOR = Qt::GlobalColor::darkBlue;
const QColor Pavlov::GRAPHCOLOR = QColor(0,0,139,0);
const std::string Pavlov::NAME = "Pavlov";
const std::string Pavlov::IMG_PATH = ":/chickPics/blue2";


Pavlov::Pavlov() : Specimen() {}

bool Pavlov::isCooperating(int enemyID){
    // if it's interacted with this enemy before
    if(m_mapRewardedOrPunished.count(enemyID)>0){
        // if it won by cooperating or lost by deflecting, cooperate
        if(m_mapRewardedOrPunished[enemyID]==true)
            return true;
        // if it won by deflecting or lost by cooperating, deflect
        else
            return false;
    }
    // if it's their first encounter, cooperate
    else
        return true;
}

void Pavlov::performUpdate(outcome o, int enemyID){
    calculateFood(o);

    bool val = true;
    // won by cooperating or lost by deflecting
    if(o==R || o==P){
        val = true;
    }
    // won by deflecting or lost by cooperating
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

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
QColor Pavlov::getColor()
{
    return this->COLOR;
}
std::string Pavlov::getPathBase()
{
    return IMG_PATH;
}
void Pavlov::update(outcome res, int enemyID){
    bool val = true;
    if(res==R || res==P){
        val = true;
    }
    else if(res==T || res==S){
        val = false;
    }

    if(m_mapRewardedOrPunished.count(enemyID)>0){
        m_mapRewardedOrPunished[enemyID]=val;
    }
    else{
        m_mapRewardedOrPunished.insert(std::pair<int,bool>(enemyID, val));
    }
}

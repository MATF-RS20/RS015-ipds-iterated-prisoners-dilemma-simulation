#include "pavlov.h"
#include "estrategy.h"

const QColor Pavlov::color = Qt::GlobalColor::darkBlue;
const std::string Pavlov::imgPath = ":/chickPics/blue2";


Pavlov::Pavlov() : Specimen() {}

bool Pavlov::isCooperating(int enemyID){
    if(m_rewardedOrPunished.count(enemyID)>0){
        if(m_rewardedOrPunished[enemyID]==true)
            return true;
        else
            return false;
    }
    else
        return true;
}
QColor Pavlov::getColor()
{
    return this->color;
}
std::string Pavlov::getPathBase()
{
    return imgPath;
}
void Pavlov::update(outcome res, int enemyID){
    bool val = true;
    if(res==R || res==P){
        val = true;
    }
    else if(res==T || res==S){
        val = false;
    }

    if(m_rewardedOrPunished.count(enemyID)>0){
        m_rewardedOrPunished[enemyID]=val;
    }
    else{
        m_rewardedOrPunished.insert(std::pair<int,bool>(enemyID, val));
    }
}

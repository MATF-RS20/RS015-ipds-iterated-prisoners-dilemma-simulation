#include "titfortat.h"
#include "estrategy.h"

const QColor TitForTat::COLOR = Qt::GlobalColor::green;
const QColor TitForTat::GRAPHCOLOR = QColor(0,255,0,50);
const std::string TitForTat::IMG_PATH = ":/chickPics/pink";

TitForTat::TitForTat() : Specimen() {}

bool TitForTat::isCooperating(int enemyID){
    if(m_mapCooperated.count(enemyID)>0){
        if(m_mapCooperated[enemyID]==true)
            return true;
        else
            return false;
    }
    else
        return true;
}

void TitForTat::performUpdate(outcome o, int enemyID){
    calculateFood(o);

    bool cooperated = true;
    if(o==R || o==T){
        cooperated = true;
    }
    else if(o==S || o==P){
        cooperated = false;
    }

    if(m_mapCooperated.count(enemyID)>0){
        m_mapCooperated[enemyID]=cooperated;
    }
    else{
        m_mapCooperated.insert(std::pair<int,bool>(enemyID, cooperated));
    }
}

QColor TitForTat::getColor()
{
    return this->COLOR;
}

std::string TitForTat::getPathBase()
{
    return IMG_PATH;
}

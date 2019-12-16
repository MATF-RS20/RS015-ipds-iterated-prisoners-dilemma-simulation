#include "titfortwotats.h"
#include "estrategy.h"
const QColor TitForTwoTats::COLOR = Qt::GlobalColor::darkGreen;
const std::string TitForTwoTats::IMG_PATH = ":/chickPics/purple";

TitForTwoTats::TitForTwoTats() : Specimen() {}

bool TitForTwoTats::isCooperating(int enemyID){
    if(m_mapDeflectionInARow.count(enemyID)>0){
        if(m_mapDeflectionInARow[enemyID]<2)
            return true;
        else
            return false;
    }
    else
        return true;
}

QColor TitForTwoTats::getColor()
{
    return this->COLOR;
}
std::string TitForTwoTats::getPathBase()
{
    return IMG_PATH;
}

void TitForTwoTats::update(outcome res, int enemyID){
    bool cooperated = true;
    if(res==R || res==T){
        cooperated = true;
    }
    else if(res==S || res==P){
        cooperated = false;
    }

    if(m_mapDeflectionInARow.count(enemyID)>0){
        if(cooperated)
            m_mapDeflectionInARow[enemyID]=0;
        else
            m_mapDeflectionInARow[enemyID]+=1;
    }
    else{
        if(!cooperated)
           m_mapDeflectionInARow.insert(std::pair<int,bool>(enemyID, 1));
    }
}

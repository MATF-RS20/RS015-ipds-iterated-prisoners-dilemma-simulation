#include "titfortwotats.h"
#include "estrategy.h"
const QColor TitForTwoTats::COLOR = Qt::GlobalColor::darkGreen;
const QColor TitForTwoTats::GRAPHCOLOR = QColor(0,139,0,0);
const std::string TitForTwoTats::NAME = "TitForTwoTats";
const std::string TitForTwoTats::IMG_PATH = ":/chickPics/green1";

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

void TitForTwoTats::performUpdate(outcome o, int enemyID){
    calculateFood(o);

    bool cooperated = true;
    if(o==R || o==T){
        cooperated = true;
    }
    else if(o==S || o==P){
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

QColor TitForTwoTats::getColor()
{
    return this->COLOR;
}

std::string TitForTwoTats::getPathBase()
{
    return IMG_PATH;
}

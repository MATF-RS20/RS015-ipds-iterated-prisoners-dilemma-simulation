#include "food.h"

Food::Food(double posX, double posY)
    :m_posX(posX)
    ,m_posY(posY)
{
    this->specimen1=nullptr;
    this->specimen2=nullptr;
    this->m_noOfSpecimen=0;
}

bool Food::addSpecimen(Specimen* newSpecimen)
{
    if(this->specimen1 == nullptr)
    {
        this->specimen1 = newSpecimen;
        return true;
    }
    else if(this->specimen2 == nullptr)
    {
        this->specimen2 = newSpecimen;
        return true;
    }
    return false;

}
void Food::releaseSpecimen()
{
    this->specimen1=nullptr;
    this->specimen2=nullptr;

}

int Food::numPresent()
{
    return this->m_noOfSpecimen;
}

#include "food.h"

Food::Food(double posX, double posY, unsigned ID)
    : m_posX(posX), m_posY(posY), m_ID(ID)
{
    specimen1 = nullptr;
    specimen2 = nullptr;
    m_noOfSpecimen = 0;
}

bool Food::addSpecimen(std::shared_ptr<Specimen> newSpecimen)
{
    if(specimen1 == nullptr)
    {
        specimen1 = newSpecimen;
        return true;
    }
    else if(specimen2 == nullptr)
    {
        specimen2 = newSpecimen;
        return true;
    }
    return false;

}
void Food::releaseSpecimen()
{
    specimen1 = nullptr;
    specimen2 = nullptr;
}

int Food::noOfSpecimen() const
{
    return m_noOfSpecimen;
}

void Food::increaseNoOfSpecimen()
{
    m_noOfSpecimen++;
}

void Food::setNoOfSpecimen(unsigned n)
{
    m_noOfSpecimen = n;
}

unsigned Food::id() const
{
    return m_ID;
}

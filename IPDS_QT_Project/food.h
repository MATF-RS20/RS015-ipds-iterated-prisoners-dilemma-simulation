#include "specimen.h"
#include <memory>

#ifndef FOOD_H
#define FOOD_H


class Food
{
public:
    Food(double posX,double posY);
    bool addSpecimen(std::shared_ptr<Specimen> newSpecimen);
    void releaseSpecimen();
    int numPresent();

    double m_posX;
    double m_posY;
    std::shared_ptr<Specimen> specimen1;
    std::shared_ptr<Specimen> specimen2;
    int m_noOfSpecimen;



};

#endif // FOOD_H

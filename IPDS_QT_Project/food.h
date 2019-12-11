#include "specimen.h"

#ifndef FOOD_H
#define FOOD_H


class Food
{
public:
    Food(double posX,double posY);
    bool addSpecimen(Specimen* newSpecimen);
    void releaseSpecimen();
    int numPresent();

    double m_posX;
    double m_posY;
    Specimen* specimen1;
    Specimen* specimen2;
    int m_noOfSpecimen;



};

#endif // FOOD_H

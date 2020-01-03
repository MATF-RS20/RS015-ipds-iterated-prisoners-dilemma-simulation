#include "specimen.h"
#include <memory>

#ifndef FOOD_H
#define FOOD_H


class Food {
public:
    Food(double posX, double posY, unsigned ID);
    bool addSpecimen(std::shared_ptr<Specimen> newSpecimen);
    void releaseSpecimen();
    void setNoOfSpecimen(unsigned n);

    int noOfSpecimen() const;
    unsigned id() const;

    std::shared_ptr<Specimen> specimen1;
    std::shared_ptr<Specimen> specimen2;

private:
    double m_posX;
    double m_posY;
    int m_noOfSpecimen;
    unsigned m_ID;


};

#endif // FOOD_H

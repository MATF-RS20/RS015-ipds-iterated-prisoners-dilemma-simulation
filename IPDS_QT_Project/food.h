#include "specimen.h"
#include <memory>

#ifndef FOOD_H
#define FOOD_H


class Food : public QGraphicsItem
{
public:
    Food(double posX, double posY, unsigned ID);
    Food(const Food &f);
    bool addSpecimen(std::shared_ptr<Specimen> newSpecimen);
    void releaseSpecimen();
    void setNoOfSpecimen(unsigned n);
    virtual ~Food() override = default;
    Food& operator=(Food&& s);
    Food& operator=(Food& s);
    int noOfSpecimen() const;
    unsigned id() const;

    std::shared_ptr<Specimen> specimen1;
    std::shared_ptr<Specimen> specimen2;

    /* Defines rough boundries for this graphic item*/
    QRectF boundingRect() const override;

    /* Defines precise shape for this graphic item */
    QPainterPath shape() const override;

    /* Draws the food in it's starting position */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;




private:
    double m_posX;
    double m_posY;
    int m_noOfSpecimen;
    unsigned m_ID;


};

#endif // FOOD_H

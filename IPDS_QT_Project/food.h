#include "specimen.h"
#include <memory>
#include <string.h>

#ifndef FOOD_H
#define FOOD_H


class Food : public QGraphicsItem
{
public:
    Food(double posX, double posY, unsigned ID);
    Food(const Food &f);
    virtual ~Food() override = default;
    Food& operator=(Food&& s);
    Food& operator=(Food& s);

    unsigned id() const;

    /* Sets number of specimen on
     * 0 (used in clearing foods for next round) */
    void resetNoOfSpecimen(void);

    /* Specimen assigned to fight over this food,
     * nullptr if none */
    std::shared_ptr<Specimen> specimen1 = nullptr;
    std::shared_ptr<Specimen> specimen2 = nullptr;

    /* Returns current number of abovementioned Specimen */
    int noOfSpecimen() const;

    /* Adds a Specimen interested in this food */
    bool addSpecimen(std::shared_ptr<Specimen> newSpecimen);

    /* Removes all Specimen from this food */
    void releaseSpecimen();

    /* Defines rough boundries for this graphic item */
    QRectF boundingRect() const override;

    /* Defines precise shape for this graphic item */
    QPainterPath shape() const override;

    /* Draws the food in it's starting position */
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;


    std::string toString();

private:
    double m_posX;
    double m_posY;
    int m_noOfSpecimen;
    unsigned m_ID;


};

#endif // FOOD_H

#include "specimen.h"

#include <cmath>

Specimen::Specimen() : specimenID(ID){
    ID++;
}
Specimen::Specimen(std::string imgPath) : specimenID(ID),imgPath(imgPath){
    ID++;
}

unsigned Specimen::ID = 0;

Specimen::Specimen(Specimen& s) : specimenID(s.ID) {}

Specimen& Specimen::operator=(Specimen& s){
    this->ID = s.ID;
    return *this;
}

QRectF Specimen::boundingRect() const
{
    qreal adjust = -0.5;
    return QRectF(-20 - adjust, -20 - adjust,
                  10 + adjust, 10 + adjust);
}

QPainterPath Specimen::shape() const
{
    QPainterPath path;

    path.addRect(-10, -20, 20, 40);
    return path;
}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
}

#define _USE_MATH_DEFINES
#include "specimen.h"
#include <iostream>
#include <cmath>


Specimen::Specimen(QColor color, std::string imgPath)
    : specimenID(ID), color(color), imgPath(imgPath)
{
    ID++;
}
Specimen::Specimen(std::string imgPath) : specimenID(ID),imgPath(imgPath){
    ID++;
}
unsigned Specimen::ID = 0;

Specimen::Specimen(Specimen& s) : QGraphicsItem(),specimenID(s.ID) {}

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
    Q_UNUSED(widget)
    painter->drawRoundedRect(0, 0, 10, 10, 5, 5);
    double angle = this->specimenID * ( (2*M_PI) / ID );
    std::cout << "ID:" << ID << "\n" << "staticCount:" << this->specimenID <<"\n" <<std::endl;
    double r = 40;
    double tmpX = r * std::cos(angle);
    double tmpY = r * std::sin(angle);

    painter->setBrush(color);
    painter->drawEllipse(-10+tmpX, -20+tmpY, 10, 10);

    painter->drawImage(QRect(-10, -20, 20, 40), QImage(QString::fromStdString(imgPath)));

}

void Specimen::advance(int step)
{
    Q_UNUSED(step)
    return;
}


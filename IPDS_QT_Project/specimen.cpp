#define _USE_MATH_DEFINES
#include "specimen.h"
#include <iostream>
#include <cmath>

unsigned Specimen::ID = 0;

Specimen::Specimen() : specimenID(ID)
{
    ID++;
}

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
    double r = 160;
    double tmpX = r * std::cos(angle);
    double tmpY = r * std::sin(angle);


//    painter->setBrush(color);
//    painter->drawEllipse(tmpX,tmpY, 10, 10);

    QPoint point(tmpX,tmpY);
    QImage image("://chickPics/purple.png");

    painter->drawImage(point, image);

//    painter->drawImage(QRect(-10, -20, 20, 40), QImage(QString::fromStdString(":/chickPics/chickPics/blue.png")));

}

void Specimen::advance(int step)
{
    Q_UNUSED(step)

    return;
}


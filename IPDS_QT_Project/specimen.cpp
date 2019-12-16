#define _USE_MATH_DEFINES
#include "specimen.h"
#include "estrategy.h"
#include <iostream>
#include <cmath>

unsigned Specimen::ID = 0;

Specimen::Specimen() : SPECIMEN_ID(ID)
{
    ID++;
}

Specimen::Specimen(Specimen& s) : QGraphicsItem(),SPECIMEN_ID(s.ID) {}

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

    /*
    * The starting position for every chick is calculated thhrough polar coordinates
    * because we want all our specimen to ultimately be in a circle.
    * So 2*PI radians is divided into totalNumberOfSpecimen angles of the same size.
    * Ergo, the formula for the angle is indexOdCurrentSpecimen * (2*PI/totalNumberOfSpecimen)
    */
    double angle = this->SPECIMEN_ID * ( (2*M_PI) / ID );
    std::cout << "ID:" << ID << "\n" << "staticCount:" << this->SPECIMEN_ID <<"\n" <<std::endl;

    /*
    * Total radius of the starting area, it's quite large atm, however, it will be downscaled to about 1/3 after
    * all the source images have been properly tampered with.
    */
    double r = 240;

    /*
     * Calculation of x and y for current specimen using polar coordinate conversion,
     * thinking about adding this as a private attribute for specimen, future Vlada
     * will handle that.
     */
    //TODO add as private clas attributes
    double tmpX = r * std::cos(angle);
    double tmpY = r * std::sin(angle);

    /*
     * Point that will signify the top-left corner of where the image will be placed.
     */
    QPoint point(tmpX-27,tmpY-23);

    /*
     * Getting the image that will represent our specimen.
     * The path is constructed by first getting the base from
     * the instnace itself, then depending on it's current position
     * we append the suffix MIRROR.png or just .png, for we want our chick to look
     * it's defeated opponent straight in the eyes when victorious.
     */
    std::cout << this->getPathBase() <<std::endl;
    QString  imgSrc = QString::fromStdString(this->getPathBase());
    if(tmpX>=0) imgSrc+="Mirror";
    imgSrc+=".png";

    QImage image(imgSrc);

    /*
     * We draw the actual image with it's top-left corner being point.
    */
    painter->drawImage(point, image);

}

void Specimen::advance(int step)
{
    Q_UNUSED(step)

    return;
}


#define _USE_MATH_DEFINES
#include "specimen.h"
#include "estrategy.h"
#include <iostream>
#include <cmath>
#define _RADIUS_ 240
unsigned Specimen::ID = 0;

Specimen::Specimen() : SPECIMEN_ID(ID)
{
    ID++;
}

Specimen::Specimen(Specimen& s) : QGraphicsItem(),SPECIMEN_ID(s.ID) {}

double Specimen::getX()
{
    return this->m_x;
}
double Specimen::getY()
{
    return this->m_y;
}

void Specimen::setX(double x)
{
    this->m_x = x;
}
void Specimen::setY(double y)
{
    this->m_y = y;
}


Specimen& Specimen::operator=(Specimen& s){
    this->ID = s.ID;
    return *this;
}

void Specimen::update(outcome o, int enemyID){
    if(enemyID==-1){
        calculateFood(T);
        return;
    }
    performUpdate(o, enemyID);
}

int Specimen::getTotalFoodEaten(void) const{
    return m_totalFoodEaten;
}

int Specimen::resetTotalFoodEaten(void){
    int tmp = m_totalFoodEaten;
    m_totalFoodEaten = 0;
    return tmp;
}

void Specimen::calculateFood(outcome o){
    switch (o) {
    case R:
        m_foodEatenLastRound = R_PAYOFF;
        break;
    case T:
        m_foodEatenLastRound = T_PAYOFF;
        break;
    case S:
        m_foodEatenLastRound = S_PAYOFF;
        break;
    case P:
        m_foodEatenLastRound = P_PAYOFF;
        break;
    }

    m_totalFoodEaten += m_foodEatenLastRound;
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
    this->m_x = _RADIUS_ * std::cos(angle);
    this->m_y = _RADIUS_ * std::sin(angle);

    /*
     * Point that will signify the top-left corner of where the image will be placed.
     */
    QPoint point( this->m_x - 27, this->m_y - 23 );

    /*
     * Getting the image that will represent our specimen.
     * The path is constructed by first getting the base from
     * the instnace itself, then depending on it's current position
     * we append the suffix MIRROR.png or just .png, for we want our chick to look
     * it's defeated opponent straight in the eyes when victorious.
     */
    std::cout << this->getPathBase() << std::endl;
    QString  imgSrc = QString::fromStdString( this->getPathBase() );
    if( this->m_x >= 0 ) imgSrc += "Mirror";
    imgSrc += ".png";

    QImage image(imgSrc);

    /*
     * We draw the actual image with it's top-left corner being point.
    */
    painter->drawImage(point, image);

}

void Specimen::advance(int step)
{
    Q_UNUSED(step)

    if( step == 0 ) return;


    return;
}


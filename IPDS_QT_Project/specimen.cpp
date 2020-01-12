#define _USE_MATH_DEFINES
#include "specimen.h"
#include "estrategy.h"
#include <cmath>
#include <iostream>
#define __RADIUS__ 240
unsigned Specimen::ID = 0;

Specimen::Specimen() : SPECIMEN_ID(ID) { ID++; }

Specimen::Specimen(const Specimen &s)
    : QGraphicsItem(),
    SPECIMEN_ID(s.ID) {}

double Specimen::getX() { return this->m_x; }
double Specimen::getY() { return this->m_y; }

void Specimen::setX(double x) { this->m_x = x; }
void Specimen::setY(double y) { this->m_y = y; }

Specimen &Specimen::operator=(Specimen &s) {
  this->ID = s.ID;
  return *this;
}

void Specimen::update(outcome o, int enemyID) {
  if (enemyID == -1) {
    calculateFood(T);
    return;
  }
  performUpdate(o, enemyID);
}

int Specimen::getTotalFoodEaten(void) const { return m_totalFoodEaten; }

int Specimen::resetTotalFoodEaten(void) {
  int tmp = m_totalFoodEaten;
  m_totalFoodEaten = 0;
  return tmp;
}

void Specimen::calculateFood(outcome o) {
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

QRectF Specimen::boundingRect() const {
  qreal adjust = -0.5;
  return QRectF(-20 - adjust, -20 - adjust, 10 + adjust, 10 + adjust);
}

QPainterPath Specimen::shape() const {
  QPainterPath path;

  path.addRect(-10, -20, 20, 40);
  return path;
}

void Specimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    //std::cout << "ID:" << ID << "\n" << "staticCount:" << SPECIMEN_ID <<"\n" <<std::endl;


    /*
     * Point that will signify the top-left corner of where the image will be placed.
     */
    QPoint point(m_x-27, m_y-23);

    /*
     * Getting the image that will represent our specimen.
     * The path is constructed by first getting the base from
     * the instnace itself, then depending on it's current position
     * we append the suffix MIRROR.png or just .png, for we want our chick to look
     * it's defeated opponent straight in the eyes when victorious.
     */
    //std::cout << getPathBase() <<std::endl;
    QString  imgSrc = QString::fromStdString(getPathBase());
    if(m_x>=0) imgSrc+="Mirror";
    imgSrc+=".png";

    QImage image(imgSrc);

    /*
     * We draw the actual image with it's top-left corner being point.
    */
    painter->drawImage(point, image);

}

void Specimen::setCoordinates(double x, double y){
    m_x = x;
    m_y = y;
}

qreal Specimen::getX(void) const{
    return m_x;
}

qreal Specimen::getY(void) const{
    return m_y;
}

void Specimen::advance(int step)
{
    Q_UNUSED(step)

      /* If invoked in phase 0, pass*/
      if( step == 0 ) return;

      /* Postavljanje pozicije u QGraphicsItemu */
      setPos(this->m_x,m_y);

  return;
}

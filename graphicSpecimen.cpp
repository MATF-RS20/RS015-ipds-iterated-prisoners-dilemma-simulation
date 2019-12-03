#include "graphicSpecimen.hpp"
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <cmath>

static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;

/*function that maps given angle to [0,2*PI]*/
static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
    {
        angle += TWO_PI;
    }

    while (angle > TWO_PI)
    {
        angle -= TWO_PI;
    }

    return angle;
}

graphicSpecimen::graphicSpecimen()
  : m_lookAngle(0.0)
  , m_speed(0.0)
  , m_globalAngle(0.0)
  , m_color(qrand() % 256, qrand() % 256, qrand() % 256)
{
    /*sets the clockwise rotation angle, default is 0*/
    setRotation(qrand() % (360 * 16));
}


QRectF graphicSpecimen::boundingRect() const
{
    qreal adjust = -0.5;
    return QRectF(-18 - adjust, -22 - adjust,
                  36 + adjust, 60 + adjust);
}


QPainterPath graphicSpecimen::shape() const
{
    /*class for storing and drawing graphical shapes*/
    QPainterPath path;
    /*args: x,y,width,height*/
    path.addRect(-10, -20, 10, 10);
    return path;
}

void graphicSpecimen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    /*drawing rough estimation of object, which can be used for minimap*/
    painter->setBrush(m_color);
    painter->drawEllipse(-10, -20, 20, 40);

    /*return the level of details that need to be used, if the object is .75 of it's original size,
      additional details are drawn*/
    const auto details =
            QStyleOptionGraphicsItem::levelOfDetailFromTransform(painter->worldTransform());
    if (details >= .75)
    {
        //TODO add details
    }
}

void graphicSpecimen::advance(int step)
{
    /*if the step is 0, the scene is getting ready for rendering,
      if the step is 1, the scene is being drawn*/
    if (!step)
    {
        return;
    }

    /*line that connects the origins of the scene and this object*/
    const QLineF lineToCenter(QPointF(0, 0), mapFromScene(0, 0));


    //TODO implement movement using dx and dy

    m_speed += (-50 + qrand() % 100) / 100.0;

    const qreal dx = sin(m_globalAngle) * 10;
    m_lookAngle = (qAbs(dx / 5) < 1) ? 0 : dx / 5;

    setRotation(rotation() + dx);
    setPos(mapToParent(0, -(3 + sin(m_speed) * 3)));
}

void graphicSpecimen::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    Q_UNUSED(event)

    delete this;
}


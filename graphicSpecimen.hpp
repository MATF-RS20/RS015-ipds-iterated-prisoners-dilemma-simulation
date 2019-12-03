#ifndef GRAPHICSPECIMEN_HPP
#define GRAPHICSPECIMEN_HPP

#include <QGraphicsItem>

class graphicSpecimen : public QGraphicsItem
{
public:
    graphicSpecimen();

    /*boundry clipping function that determines if the QGraphicsItem should be drawn*/
    QRectF boundingRect() const override;

    /*function for detecting shape collision with other QGraphicsItems*/
    QPainterPath shape() const override;

    /*function that draws the current QGraphicsItem*/
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    /*function that is triggered when this object is clicked*/
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

protected:

    /*function that is used for iterated animation, is called for every change*/
    void advance(int step) override;

private:
    qreal  m_xPosition;
    qreal  m_yPosition;
    qreal  m_lookAngle;
    qreal  m_speed;
    qreal  m_globalAngle;
    QColor m_color;

};

#endif // GRAPHICSPECIMEN_HPP

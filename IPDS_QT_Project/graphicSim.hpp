#include <QGraphicsItem>
#include "specimen.h"
#include "simulation.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#ifndef GRAPHICSPECIMEN_HPP
#define GRAPHICSPECIMEN_HPP



class graphicSim : public QGraphicsItem, public Simulation
{
public:
    //TODO add simulation constructor and store in private field
    graphicSim(int foodNo, std::vector<int> &specimenNoInfo, MainWindow window);

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

    /////////////////
    void drawGraphIter();
    /////////////////


protected:

    /*function that is used for iterated animation, is called for every change*/
    void advance(int step) override;

private:

    MainWindow m_window;
    qreal  m_xPosition;
    qreal  m_yPosition;
    qreal  m_lookAngle;
    qreal  m_speed;
    qreal  m_globalAngle;
    QColor m_color;

};

#endif // GRAPHICSPECIMEN_HPP

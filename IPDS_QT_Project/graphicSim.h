#include <QGraphicsItem>
#include <vector>
#include "specimen.h"
#include "food.h"
#include "simulation.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#ifndef GRAPHICSPECIMEN_HPP
#define GRAPHICSPECIMEN_HPP



class GraphicSim : public Simulation
{
public:

    GraphicSim(int foodNo, std::vector<int> &specimenNoInfo);
    ~GraphicSim();
    void initializeFood(int foodNo);
    void drawGraphIter();
    void show();
    void addItems(QGraphicsScene& scene);


    std::vector<int> m_posVector;


protected:

    /*function that is used for iterated animation, is called for every change*/
    void advance(int step);

private:

    qreal  m_xPosition;
    qreal  m_yPosition;
    std::vector<Food> m_foodVector;
};

#endif // GRAPHICSPECIMEN_HPP

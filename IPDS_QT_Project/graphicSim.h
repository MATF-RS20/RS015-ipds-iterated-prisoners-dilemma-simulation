#include <QGraphicsItem>
#include <vector>
#include "specimen.h"
#include "food.h"
#include "simulation.h"
#include "ui_mainwindow.h"
#include "graphics.h"
#include "specimen.h"
#include "simulation.h"
#include "estrategy.h"
#include <cmath>
#include <cstdlib>

#ifndef GRAPHICSPECIMEN_HPP
#define GRAPHICSPECIMEN_HPP



class GraphicSim : public Simulation
{
public:

    GraphicSim(unsigned foodNo, std::vector<unsigned> &specimenNoInfo);
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

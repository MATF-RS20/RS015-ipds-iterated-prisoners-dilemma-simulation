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
#include <QObject>
#include <QTimer>


#ifndef GRAPHICSPECIMEN_HPP
#define GRAPHICSPECIMEN_HPP



class GraphicSim : public Simulation, public QObject
{
public:

    GraphicSim(unsigned foodNo, std::vector<unsigned> &specimenNoInfo);
    ~GraphicSim();

    /*Function that is used for iterated "animation" */
    void show();

    /*Unified function for adding all specimen and food from the scene*/
    void addItems(QGraphicsScene& scene);

public slots:
    /*Used as a simulation wrapper*/
    void iterate(void);



private:
    QGraphicsScene* m_scene;

    /*Specimen draw radius*/
    double m_radius;

    /*Indicator that tells us if it's time to chase food or repaint the specimen in their
    * starting positions.
    */
    bool m_isFoodStage;
    int m_iterCount;
    QTimer m_timer;

};

#endif // GRAPHICSPECIMEN_HPP

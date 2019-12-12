#include "mainwindow.h"
#include "graphics.h"
#include "graphicSim.hpp"
#include "simulation.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{

    /*hard coded example*/
    int foodCount = 5;
    std::vector<int> specimenNoInfo{1,2,3,4,5,6,7};

    /*app and window init*/
    QApplication a(argc, argv);
    MainWindow w;

    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));


    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);


    graphicSim* gs = new graphicSim(foodCount,specimenNoInfo);

    /* Adding items of type specimen to the scene*/
    gs->addItems(scene);

    QGraphicsView view(&scene);

    //view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.setWindowTitle("Simulacija");
    view.resize(600, 400);
    view.show();

    w.show();
    return a.exec();
}

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

    int foodCount = 5;
    QApplication a(argc, argv);
    MainWindow w;

    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));


    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    std::vector<int> specimenNoInfo;
    graphicSim* gs = new graphicSim(foodCount,specimenNoInfo);
    gs
    //scene.addItem(gs);

    QGraphicsView view(&scene);




    // Omogucava se da korisnik misem moze da pomera glavni pogled
    // na scenu (drag and drop akcija).
    view.setDragMode(QGraphicsView::ScrollHandDrag);

    view.setWindowTitle("Simulacija");
    view.resize(600, 400);
    view.show();

    w.show();
    return a.exec();
}

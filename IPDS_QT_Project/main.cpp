#include "mainwindow.h"
#include "graphics.h"
#include "graphicSim.h"
#include "simulation.h"
#include <QtGui>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{

    /*app and window init*/
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}

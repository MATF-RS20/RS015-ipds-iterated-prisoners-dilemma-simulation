#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::plot();
}

void MainWindow::plot()
{
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->plotWidget->addGraph();

    ui->plotWidget->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->plotWidget->xAxis->setLabel("x");
    ui->plotWidget->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->plotWidget->xAxis->setRange(-1, 1);
    ui->plotWidget->yAxis->setRange(0, 1);
    ui->plotWidget->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonPlay_clicked()
{
    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));

    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(-300, -300, 600, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    QSlider *slider = ui->verticalLayout->findChild<QSlider *>("foodSlider");
    int foodCount = 5;//slider->value();

    /* TODO: get specimenNoInfo from GUI */
    std::vector<int> specimenNoInfo{1,2,3,4,5,6,7};

    m_gs = new GraphicSim(foodCount, specimenNoInfo);

    /* Adding items of type specimen to the scene*/
    m_gs->addItems(*scene);

    m_view = new QGraphicsView(scene);

    //view.setDragMode(QGraphicsView::ScrollHandDrag);

    m_view->setWindowTitle("Simulacija");
    m_view->resize(600, 400);
    m_view->show();

    std::cout << "Play";
}

void MainWindow::on_pushButtonStop_clicked()
{
    std::cout << "Stop";
}

void MainWindow::on_pushButtonPause_clicked()
{
    std::cout << "Pause";
}



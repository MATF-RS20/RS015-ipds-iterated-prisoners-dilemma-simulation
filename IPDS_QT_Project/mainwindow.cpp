#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::plot();

    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(-300, -300, 600, 600);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

void MainWindow::plot()
{
    StateHistory sh = m_gs->graphInfo();
    QVector<double> x(sh.iterationNo());
    std::iota(x.begin(), x.end(), 0);

    for(int i=0; i<COUNT; i++){
        ui->plotWidget->addGraph();

        std::vector<int> y_tmp = sh.getByStrategy(static_cast<strategy>(i));
        QVector<double> y;
        for(int i : y_tmp){
            y.append(static_cast<double>(i));
        }

        ui->plotWidget->graph(i)->setData(x, y);

        ui->plotWidget->xAxis->setLabel("Iteration");
        ui->plotWidget->yAxis->setLabel("Specimen");

        ui->plotWidget->xAxis->setRange(0, sh.iterationNo());
        ui->plotWidget->yAxis->setRange(0, 200); // HACK: Hardcoded random value
    }

    ui->plotWidget->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_scene;
}


void MainWindow::on_pushButtonPlay_clicked()
{
    if(!m_playing){
        QSlider* foodSlider = ui->centralwidget->findChild<QSlider*>("foodSlider");
        int foodCount = foodSlider->value();

        /* TODO: get specimenNoInfo from GUI */
        std::vector<int> specimenNoInfo{1,2,3,4,5,6,7};

        m_gs = new GraphicSim(foodCount, specimenNoInfo);

        /* Adding items of type specimen to the scene*/
        m_gs->addItems(*m_scene);

        m_view = new QGraphicsView(m_scene);

        m_view->setWindowTitle("Simulacija");
        m_view->resize(600, 400);
        m_view->show();

        m_playing = true;
    }
}

void MainWindow::on_pushButtonStop_clicked()
{
    if(m_playing){
        m_view->close();
        delete m_view;
        delete m_gs;

        m_playing = false;
    }
}

void MainWindow::on_pushButtonPause_clicked()
{
    std::cout << "Pause";
}



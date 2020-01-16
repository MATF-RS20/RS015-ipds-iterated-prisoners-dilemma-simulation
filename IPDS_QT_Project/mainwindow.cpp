#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(Ui::MainWindow())
{
    ui.setupUi(this);

    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
}


MainWindow::~MainWindow()
{
    delete m_scene;
}

void MainWindow::addDefaultScene(void){
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(-300, -300, 600, 600);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(plot()));
    m_timer.start(1000 / 60);
    this->ui.listWidget->setCurrentRow(0);
    ui.foodNo->setValue(15);
    m_currentStratNo=0;
}

void MainWindow::setPlotColors(){
    QPen pen;
    for(int i=0; i<COUNT; i++){
        strategy s = static_cast<strategy>(i);
        switch(s){
            case E_DOVE:
                pen.setColor(Dove::COLOR);
            break;
            case E_HAWK:
                pen.setColor(Hawk::COLOR);
            break;
            case E_PAVLOV:
                pen.setColor(Pavlov::COLOR);
            break;
            case E_RANDOM:
                pen.setColor(AllRandom::COLOR);
            break;
            case E_TITFORTAT:
                pen.setColor(TitForTat::COLOR);
            break;
            case E_TITFORTWOTATS:
                pen.setColor(TitForTwoTats::COLOR);
            break;
            case E_TWOTITSFORTAT:
                pen.setColor(TwoTitsForTat::COLOR);
            break;
            default:
            break;
        }
        ui.plotWidget->graph(i)->setPen(pen);
    }
}

void MainWindow::plot()
{
    StateHistory sh = m_gs->graphInfo();
    QVector<double> x(sh.iterationNo());
    std::iota(x.begin(), x.end(), 0);

    for(int i=0; i<COUNT; i++){
        ui.plotWidget->addGraph();

        std::vector<unsigned> y_tmp = sh.getByStrategy(static_cast<strategy>(i));
        QVector<double> y;
        for(int i : y_tmp){
            y.append(static_cast<double>(i));
        }

        ui.plotWidget->graph(i)->setData(x, y);


    }

    setPlotColors();

    ui.plotWidget->xAxis->setLabel("Iteration");
    ui.plotWidget->yAxis->setLabel("Specimen");

    ui.plotWidget->xAxis->setRange(0, sh.iterationNo());
    ui.plotWidget->yAxis->setRange(0, 200); // HACK: Hardcoded random value

    ui.plotWidget->replot();
}


void MainWindow::on_pushButtonPlay_clicked()
{
    unsigned foodCount = ui.foodNo->value();
    if(!m_playing && foodCount>=15){

        /* TODO: get specimenNoInfo from GUI */


        m_gs = new GraphicSim(foodCount, m_specimenNoInfo);

        /* Adding items of type specimen to the scene*/
        m_gs->addItems(*m_scene);

        m_view = new QGraphicsView(m_scene);

        m_view->setWindowTitle("Simulacija");
        m_view->resize(800, 600);

        m_view->show();

        m_playing = true;

        /*TODO: Implement food counter lcd*/

        //QObject::connect(&foodCount, SIGNAL(), m_scene, SLOT(update()));
        QObject::connect(&m_timer, SIGNAL(timeout()), m_scene, SLOT(update()));
        m_timer.start(1000 / 60);


    }
}

void MainWindow::on_pushButtonStop_clicked()
{
    if(m_playing){
        MainWindow::plot();
        m_view->close();
        delete m_view;
        delete m_gs;

        m_playing = false;
    }
}

void MainWindow::on_pushButtonPause_clicked()
{
    if(paused){
        m_timer.start(1000 / 33);
        paused = false;
    }
    else{
        m_timer.stop();
        MainWindow::plot();
        paused = true;
    }
}


void MainWindow::on_changeSpecimenNumber_clicked()
{
    /*Changes the values in the ui to match the current number of specimens for the selected strategy*/
    m_currentStratNo = this->ui.listWidget->currentRow();
    QString curStratName = this->ui.listWidget->currentItem()->text();
    this->ui.specimenName->setText(curStratName);
    this->ui.specimenNo->setValue(static_cast<int>(m_specimenNoInfo[m_currentStratNo]));
    this->ui.specimenDescription->setText(curStratName);
}

void MainWindow::on_updateButton_clicked()
{
    m_specimenNoInfo[m_currentStratNo]=this->ui.specimenNo->value();
    this->ui.specimenNo->setValue(static_cast<int>(m_specimenNoInfo[m_currentStratNo]));
    //this->ui.specimenDescription->setText(curStratName);
}

void MainWindow::on_foodCounter_overflow()
{

}

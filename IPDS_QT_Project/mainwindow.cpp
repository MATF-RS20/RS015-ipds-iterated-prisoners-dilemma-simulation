#include "mainwindow.h"
#include "help.h"

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
    ui.listWidget->setCurrentRow(0);
    ui.foodNo->setValue(15);
    m_currentStratNo=0;
}

QPixmap MainWindow::getCurrentSpecimenPhoto() {
    return m_currentSpecimenPhoto;
}

void MainWindow::setCurrentSpecimenPhoto() {

    switch(m_currentStratNo) {
        // Hawk
        case 1:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/red");
            break;
        // Pavlov
        case 2:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/blue2");
            break;
        // Random
        case 3:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/green");
            break;
        // Tit-for-Tat
        case 4:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/pink");
            break;
        // Tit-for-two-Tats
        case 5:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/purple");
            break;
        // Two-Tits-for-Tat
        case 6:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/blue3");
            break;
        // Dove
        default:
            m_currentSpecimenPhoto = QPixmap(":/chickPics/blue");
    }

}

void MainWindow::setCurrentSpecimenDescription() {

    switch(m_currentStratNo) {
        case 1:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Hawks are meanies. They always deflect no matter what. They're those creatures that nobody wants to hang out with.\n") +
                                             "They do not take into account previous encounters.");
            break;
        case 2:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Pavlovs have put some thought in this. After realizing it's best for them to be careful around others and make sure ") +
                                             "that as much as possible resources end up in their possession, they developed a strategy.\n" +
                                             "If they encounter a creature known from before they will repeat the same action from the last encounter, " +
                                             "if the last encounter was a win for them (they deflected and enemy didn't, or both sides were nice to each other), or " +
                                             "change their behavior, if the last encounter was a loss.\n" +
                                             "However, they believe that everybody deserves a chance, so if they encounter an unknown creature, they will cooperate and be kind.");
            break;
        case 3:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Randoms do not believe in strategies or principles.\nYou never know what to expect from them, since the chance that they'll ") +
                                             "cooperate and chance that they'll deflect are pretty much equal. Nobody ever figured out the pattern.");
            break;
        case 4:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Tit-For-Tats think that giving others the taste of their own medicine is the best way to go.\n They'll always start with cooperation ") +
                                             "on the first encounter with someone, but after that they'll just do whatever the enemy did the last time they saw each other.");
            break;
        case 5:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Tit-For-Two-Tats are similar to their neighbour Tit-For-Tat, but a bit more forgiving. Maybe somebody has a bad day?\n") +
                                             "They start by cooperating and keep cooperating until the other one deflects twice in a row. As long as the other one's " +
                                             "last two moves were deflections, they will keep deflecting.");
            break;
        case 6:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Two-Tits-For-Tats are a bit more punishing than their neighbours. They're exactly the opposite of Tit-For-Two-Tats and ") +
                                             "they think everybody should suffer the consequences for their evildoings.\n" +
                                             "They start by cooperating, but every time that the other creature deflects, TwoTitsForTats will deflect next two rounds.");
            break;
        default:
            m_currentSpecimenDescriptionText = QString::fromStdString(std::string("Doves are good creatures! They always cooperate with the other creature no matter what.\nThey do not take into account ") +
                                            "previous encounters nor they holds any grudges.");
    }
}

QString MainWindow::getCurrentSpecimenDescription() {
    return m_currentSpecimenDescriptionText;
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
    int yMax=0;
    for(int i=0; i<COUNT; i++){
        ui.plotWidget->addGraph();

        std::vector<unsigned> y_tmp = sh.getByStrategy(static_cast<strategy>(i));
        QVector<double> y;
        for(int i : y_tmp){
            y.append(static_cast<double>(i));
            yMax = yMax>i ? yMax : i;
        }

        ui.plotWidget->graph(i)->setData(x, y);
    }
    setPlotColors();

    ui.plotWidget->xAxis->setLabel("Iteration");
    ui.plotWidget->yAxis->setLabel("Specimen");

    ui.plotWidget->xAxis->setRange(0, sh.iterationNo());
    ui.plotWidget->yAxis->setRange(0, yMax); // HACK: Hardcoded random value

    ui.plotWidget->replot();
}


void MainWindow::on_pushButtonPlay_clicked()
{
    unsigned foodCount = ui.foodNo->value();
    //TODO: warning prompt
    if(!m_playing && foodCount >= 15 && foodCount <= 100){

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
    m_currentStratNo = ui.listWidget->currentRow();
    setCurrentSpecimenDescription();
    setCurrentSpecimenPhoto();
    QString curStratName = ui.listWidget->currentItem()->text();
    ui.specimenName->setText(curStratName);
    ui.specimenNo->setValue(static_cast<int>(m_specimenNoInfo[m_currentStratNo]));
    ui.specimenDescription->setText(getCurrentSpecimenDescription());


    // get label dimensions
    int w = ui.labelPic->width()*0.7;
    int h = ui.labelPic->height()*0.7;
    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui.labelPic->setPixmap(getCurrentSpecimenPhoto().scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_updateButton_clicked()
{
    m_specimenNoInfo[m_currentStratNo]=ui.specimenNo->value();
    ui.specimenNo->setValue(static_cast<int>(m_specimenNoInfo[m_currentStratNo]));
    //ui.listWidget->currentItem()->setText()
    //ui.specimenDescription->setText(curStratName);
}

void MainWindow::on_foodCounter_overflow()
{

}

void MainWindow::on_pushButton_clicked()
{
    m_secondWindow = new Help();
    m_secondWindow->show();

}

#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(Ui::MainWindow())
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui.setupUi(this);
    setWindowIcon(QIcon(":/chickPics/icon.png"));

    QObject::connect(ui.listWidget,SIGNAL(itemSelectionChanged()),this,SLOT(updateUI()));
    qsrand(static_cast<unsigned>(QTime(0,0,0).secsTo(QTime::currentTime())));
}


MainWindow::~MainWindow()
{
    delete m_scene;
}

void MainWindow::addDefaultScene(void){
    m_scene = new QGraphicsScene();
    m_scene->setSceneRect(-150, -150, 300, 300);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui.foodNo->setValue(15);


}

QPixmap MainWindow::getCurrentSpecimenPhoto() {
    return m_currentSpecimenPhoto;
}

void MainWindow::setCurrentSpecimenPhoto() {

    switch(m_currentStratNo) {
        // Hawk
        case 1:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/hawk.png");
            break;
        // Pavlov
        case 2:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/pavlov.png");
            break;
        // Random
        case 3:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/random.png");
            break;
        // Tit-for-Tat
        case 4:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/titfortat.png");
            break;
        // Tit-for-two-Tats
        case 5:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/titfortwotats.png");
            break;
        // Two-Tits-for-Tat
        case 6:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/twotitsfortat.png");
            break;
        // Dove
        default:
            m_currentSpecimenPhoto = QPixmap(":/hrChicks/dove.png");
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
    QBrush brush;
    for(int i=0; i<COUNT; i++){
        strategy s = static_cast<strategy>(i);
        switch(s){
            case E_DOVE:
                pen.setColor(Dove::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(Dove::GRAPHCOLOR));
            break;
            case E_HAWK:
                pen.setColor(Hawk::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(Hawk::GRAPHCOLOR));
            break;
            case E_PAVLOV:
                pen.setColor(Pavlov::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(Pavlov::GRAPHCOLOR));
            break;
            case E_RANDOM:
                pen.setColor(AllRandom::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(AllRandom::GRAPHCOLOR));
            break;
            case E_TITFORTAT:
                pen.setColor(TitForTat::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(TitForTat::GRAPHCOLOR));
            break;
            case E_TITFORTWOTATS:
                pen.setColor(TitForTwoTats::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(TitForTwoTats::GRAPHCOLOR));
            break;
            case E_TWOTITSFORTAT:
                pen.setColor(TwoTitsForTat::COLOR);
                //ui.plotWidget->graph(i)->setBrush(QBrush(TwoTitsForTat::GRAPHCOLOR));
            break;
            default:
            break;
        }

        ui.plotWidget->graph(i)->setPen(pen);

    }
}

void MainWindow::plot()
{
    /*Fetching history of specimen numbers up until now*/
    StateHistory sh = m_gs->graphInfo();
    QVector<double> x(sh.iterationNo());
    std::iota(x.begin(), x.end(), 0);
    QVector<double> xSums(sh.iterationNo(),0);

    /*Variable that will be used for upper limit of y, for it can very easily skyrocket*/
    int yMax=0;

    /*
     * Because we'll be using the same graph widget multiple times for different graphs to create the illusion of motion
     * we need to clear all previous data so that the graphs don't overlap
     */
    ui.plotWidget->clearGraphs();

    /*Vector of y values (current number of specimen of a certain type in the current population) for every strategy*/
    QVector<QVector<double>> y;

    /*Vector that indicates whether the i-th type of specimen is present in the current simulation*/
    std::vector<bool> isPresent(COUNT,true);

    for(int i=0; i<COUNT; ++i){

        y.append(QVector<double>());

        /*Fetches from state history the number of specimen over time of a specific type*/
        std::vector<unsigned> y_tmp = sh.getByStrategy(static_cast<strategy>(i));

        /*If a specimen ain't present at the begining, he sure ain't gonna suddenly appear in the middle of the simulation*/
        if(y_tmp[0]==0)isPresent[i]=false;

        /*Appends number of specimen in a certain iteration until it hits 0*/
        for(int j=0; j<static_cast<int>(y_tmp.size()); ++j)
        {
            if(y_tmp[j]==0)
            {
                y[i].append(static_cast<double>(y_tmp[j])+xSums[j]);
                break;
            }
            y[i].append(static_cast<double>(y_tmp[j])+xSums[j]);

            /*We keep track of the sum in a certain iteration for upcoming strategies*/
            xSums[j]+=y_tmp[j];
            yMax = yMax>xSums[j] ? yMax : xSums[j];

        }


    }
    /*Generates the graphs in reverse order to prevent overlaping (this is in case we ever want to use brushes to paint the seperate graphs)*/

    for(int i=0; i<COUNT; ++i)
    {
        ui.plotWidget->addGraph();
    }

    /*Deduces the strategy name from it's index*/
    for(int i=COUNT-1; i>=0; i--)
    {
        QString curStratName;
        switch(i) {
            case 1:
                curStratName = QString::fromStdString(Hawk::NAME);
                break;
            case 2:
                curStratName = QString::fromStdString(Pavlov::NAME);
                break;
            case 3:
                curStratName = QString::fromStdString(AllRandom::NAME);
                break;
            case 4:
                curStratName = QString::fromStdString(TitForTat::NAME);
                break;
            case 5:
                curStratName = QString::fromStdString(TitForTwoTats::NAME);
                break;
            case 6:
                curStratName = QString::fromStdString(TwoTitsForTat::NAME);
                break;
            default:
                curStratName = QString::fromStdString(Dove::NAME);
        }

        ui.plotWidget->graph(i)->setName(curStratName);
        if(isPresent[i]==false)continue;
        ui.plotWidget->graph(i)->setData(x, y[i]);

    }

    setPlotColors();

    ui.plotWidget->xAxis->setLabel("Iteration");
    ui.plotWidget->yAxis->setLabel("Specimen");

    ui.plotWidget->xAxis->setRange(0, sh.iterationNo());
    ui.plotWidget->yAxis->setRange(0, yMax);

    ui.plotWidget->legend->setVisible(true);

    ui.plotWidget->replot();

}


void MainWindow::on_pushButtonPlay_clicked()
{
    unsigned foodCount = ui.foodNo->value();
    if(!m_playing && foodCount >= 15 && foodCount <= 100){


        m_gs = new GraphicSim(foodCount, m_specimenNoInfo);

        /* Adding items of type specimen to the scene*/
        m_gs->addItems(*m_scene);
        m_view = new QGraphicsView(m_scene);


        m_view->setWindowTitle("Simulation");
        m_view->resize(800, 600);

        m_view->show();

        m_playing = true;

        /*Connects the same timer to the plot and simulation for parallel ploting and simulating*/
        QObject::connect(&m_timer, SIGNAL(timeout()), m_scene, SLOT(update()));
        QObject::connect(&m_timer, SIGNAL(timeout()), this, SLOT(plot()));
        m_timer.start(100);



    }else{
        /*Warning prompt*/
        QMessageBox::information(this,tr("Warning"),tr("The quantity of food must be in the interval [15,100]"));
    }
}

void MainWindow::on_pushButtonStop_clicked()
{
    if(m_playing){
        m_timer.stop();
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


void MainWindow::updateUI()
{
    m_smtIsSelected=true;
    /*Changes the values in the ui to match the current number of specimens for the selected strategy*/
    m_currentStratNo = ui.listWidget->currentRow();
    setCurrentSpecimenDescription();
    setCurrentSpecimenPhoto();
    std::string tmpStratName = ui.listWidget->currentItem()->text().toStdString();
    QString curStratName = QString::fromStdString(tmpStratName.substr(0,tmpStratName.find('-')-1));
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
    if(!m_smtIsSelected) return;
    int newValue = m_specimenNoInfo[m_currentStratNo] = ui.specimenNo->value();
    ui.specimenNo->setValue(newValue);

    /*Generates the new entry so that it contains the current number of specimen of a certain type*/
    switch(m_currentStratNo) {
        case 1:
            ui.listWidget->currentItem()->setText(QString::fromStdString(Hawk::NAME + " - " + std::to_string(newValue)));
            break;
        case 2:
            ui.listWidget->currentItem()->setText(QString::fromStdString(Pavlov::NAME + " - " + std::to_string(newValue)));
            break;
        case 3:
            ui.listWidget->currentItem()->setText(QString::fromStdString(AllRandom::NAME + " - " + std::to_string(newValue)));
            break;
        case 4:
            ui.listWidget->currentItem()->setText(QString::fromStdString(TitForTat::NAME + " - " + std::to_string(newValue)));
            break;
        case 5:
            ui.listWidget->currentItem()->setText(QString::fromStdString(TitForTwoTats::NAME + " - " + std::to_string(newValue)));
            break;
        case 6:
           ui.listWidget->currentItem()->setText(QString::fromStdString(TwoTitsForTat::NAME + " - " + std::to_string(newValue)));
            break;
        default:
            ui.listWidget->currentItem()->setText(QString::fromStdString(Dove::NAME + " - " + std::to_string(newValue)));
    }
}




void MainWindow::on_newWindowButton_clicked()
{
    m_secondWindow = new Help();
    m_secondWindow->setAttribute( Qt::WA_DeleteOnClose );
    m_secondWindow->show();
}

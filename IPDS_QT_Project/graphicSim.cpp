#define _USE_MATH_DEFINES

#include "graphicSim.h"

static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;


GraphicSim::GraphicSim(unsigned foodNo, std::vector<unsigned> &specimenNoInfo)
    : Simulation(foodNo, specimenNoInfo),m_isFoodStage(false) {

    initializeFood(foodNo);
    this->m_iterCount = 0;
    show();



    QObject::connect(&m_timer, &QTimer::timeout, this, &GraphicSim::iterate);
    m_timer.start(2000);
}

GraphicSim::~GraphicSim() {}

void GraphicSim::iterate(void){
    std::cout << "iteration:"<< m_iterCount << std::endl;
    m_iterCount++;

    if(m_isFoodStage){
        simulate();
        show();
    }else{
        show();
    }
}

void GraphicSim::show() {
    int sum = 0;
    std::cout << "No of specimen:" << m_specimenNo << std::endl;
    for (unsigned i = 0; i < strategy::COUNT; ++i) {
        std::cout << "No of specimen of type "<< i << ": " << m_specimen[i].size() << std::endl;
        for (unsigned long j = 0; j < m_specimen[i].size(); ++j) {

            if(!m_isFoodStage){
                // specimenIndex * 2PI / totalNoOfSpecimen
                double angle = sum * (2*M_PI) / m_specimenNo;
                sum++;

                // Total radius of the starting area
                double r = 100;
                //std::cout << "angle:"<<(2*M_PI) / m_specimenNo << std::endl;

                // Polar coordinates
                double tmpX = r * std::cos(angle);
                double tmpY = r * std::sin(angle);

                // Setting them in the appropriate specimen
                m_specimen[i][j]->setCoordinates(tmpX, tmpY);

                m_specimen[i][j]->show();
            }else{
                m_specimen[i][j]->setCoordinates( m_specimen[i][j]->getTargetX() , m_specimen[i][j]->getTargetY() );
                m_specimen[i][j]->show();

            }
        }
    }
    m_isFoodStage = m_isFoodStage ? false : true ;

    unsigned tmpFoodNo = m_foodVector.size();
    for (unsigned i = 0; i < tmpFoodNo; ++i)
    {
       // std::cout << m_foodVector[i].toString() << std::endl ;
       m_foodVector[i].setVisible(true);
    }
}

void GraphicSim::addItems(QGraphicsScene &scene) {
    for (auto stratVector : m_specimen) {
        for (auto tmpSpecimen : stratVector) {
          scene.addItem(tmpSpecimen.get());
        }
    }
    for (auto food : m_foodVector) {
        scene.addItem(&food);
    }
}

void GraphicSim::initializeFood(int foodNo) {
    // TODO add global drawing center,scale to R
    double randa, randr;
    double centerX = -10.0;
    double centerY = -20.0;

    /*Generates random position inside a circle*/
    /*randr signifies the distance from the center, randa signifies the angle for
    * the polar coordinates*/
    for (int i = 0; i < foodNo; ++i) {
        // TODO clean up this blasphemous random number generation and pi
        // representation
        // TODO tweak size of r to match window size

        randr = static_cast<double>(qrand()) / RAND_MAX;
        double r = randr * sqrt(centerX * centerX + centerY * centerY);

        randa = static_cast<double>(qrand()) / RAND_MAX;
        double tmpX = r * std::cos(randa * 2 * M_PI);
        double tmpY = r * std::sin(randa * 2 * M_PI);

        /*Adds the generated food to the appropriate attribute*/
        m_foodVector.emplace_back(tmpX, tmpY, i);
    }
}

void GraphicSim::moveSpecimen()
{
    double dx(0.1),dy(0.1);
    for ( auto stratVector : this->m_specimen )
    {
        for( auto tSpecimenPtr : stratVector )
        {
            Specimen* tSpecimen = tSpecimenPtr.get();
            auto tX = tSpecimen->getX();
            auto tY = tSpecimen->getY();
            tSpecimen->setCoordinates(tX+dx,tY+dy);
        }
    }
    return;
}

void GraphicSim::advance(int step){
    if(step == 0)
        return;
    else
    {

    }

    show();
}

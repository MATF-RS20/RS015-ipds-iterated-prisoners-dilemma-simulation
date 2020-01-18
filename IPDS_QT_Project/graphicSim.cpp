#define _USE_MATH_DEFINES

#include "graphicSim.h"

static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;


GraphicSim::GraphicSim(unsigned foodNo, std::vector<unsigned> &specimenNoInfo)
    : Simulation(foodNo, specimenNoInfo),m_isFoodStage(false) {

    // Total radius of the starting area
    m_radius = 200;
    this->m_iterCount = 0;
    show();



    QObject::connect(&m_timer, &QTimer::timeout, this, &GraphicSim::iterate);
    m_timer.start(1000);
}

GraphicSim::~GraphicSim() {}

void GraphicSim::iterate(void){
    std::cout << "iteration:"<< m_iterCount << std::endl;
    m_iterCount++;

    if(m_isFoodStage){
        simulate();
        show();
        for(auto spec : m_newSpecimen){
            m_scene->addItem(spec.get());
        }
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

                // Polar coordinates
                double tmpX = m_radius * std::cos(angle);
                double tmpY = m_radius * std::sin(angle);

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

    unsigned tmpFoodNo = m_foodsActive.size();
    for (unsigned i = 0; i < tmpFoodNo; ++i)
    {
       // std::cout << m_foodVector[i].toString() << std::endl ;
        if(m_foodsActive[i] != nullptr)
            m_foodsActive[i]->show();
    }
}

void GraphicSim::addItems(QGraphicsScene &scene) {
    m_scene = &scene;
    for (auto stratVector : m_specimen) {
        for (auto tmpSpecimen : stratVector) {
          scene.addItem(tmpSpecimen.get());
        }
    }
    for (unsigned i = 0; i < m_foodsActive.size(); ++i)
    {
        if(m_foodsActive[i] != nullptr)
            scene.addItem(m_foodsActive[i]);
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

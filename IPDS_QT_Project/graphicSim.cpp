#define _USE_MATH_DEFINES

#include "graphicSim.h"

static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;

/*function that maps given angle to [0,2*PI]*/
static qreal normalizeAngle(qreal angle) {
  while (angle < 0) {
    angle += TWO_PI;
  }

  while (angle > TWO_PI) {
    angle -= TWO_PI;
  }

  return angle;
}

GraphicSim::GraphicSim(unsigned foodNo, std::vector<unsigned> &specimenNoInfo)
    : Simulation(foodNo, specimenNoInfo) {

    show();

    initializeFood(foodNo);

    QObject::connect(&m_timer, &QTimer::timeout, this, &GraphicSim::iterate);
    m_timer.start(1000);
}

GraphicSim::~GraphicSim() {}

void GraphicSim::iterate(void){
    std::cout << "iterate" << std::endl;
    show();
    simulate();
}

void GraphicSim::show() {
    int sum = 0;
    for (unsigned i = 0; i < strategy::COUNT; ++i) {
        for (unsigned long j = 0; j < m_specimen[i].size(); ++j) {

            // specimenIndex * 2PI / totalNoOfSpecimen
            double angle = sum * (2*M_PI) / m_specimenNo;
            sum++;

            // Total radius of the starting area
            double r = 100;

            // Polar coordinates
            double tmpX = r * std::cos(angle);
            double tmpY = r * std::sin(angle);

            // Setting them in the appropriate specimen
            m_specimen[i][j]->setCoordinates(tmpX, tmpY);

            m_specimen[i][j]->show();
        }
    }
}

void GraphicSim::addItems(QGraphicsScene &scene) {
    for (auto stratVector : m_specimen) {
        for (auto tmpSpecimen : stratVector) {
          scene.addItem(tmpSpecimen.get());
        }
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
    show();
}

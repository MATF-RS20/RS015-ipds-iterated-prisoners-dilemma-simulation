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

    /*Initializes Simulation and by extension, all specimen instances*/
    unsigned strategyCount = strategy::COUNT;

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
    unsigned strategyCount = strategy::COUNT;
    int sum = 0;
    for (unsigned i = 0; i < strategyCount; ++i) {
        for (unsigned long j = 0; j < m_specimen[i].size(); ++j) {
            /*
            * The starting position for every chick is calculated thhrough polar coordinates
            * because we want all our specimen to ultimately be in a circle.
            * So 2*PI radians is divided into totalNumberOfSpecimen angles of the same size.
            * Ergo, the formula for the angle is indexOdCurrentSpecimen * (2*PI/totalNumberOfSpecimen)
            */
            double angle = sum * (2*M_PI) / m_specimenNo;
            sum++;

            /*
            * Total radius of the starting area, it's quite large atm, however, it will be downscaled to about 1/3 after
            * all the source images have been properly tampered with.
            */
            double r = 240;

            /*
             * Calculation of x and y for current specimen using polar coordinate conversion,
             * thinking about adding this as a private attribute for specimen, future Vlada
             * will handle that.
             */
            //TODO add as private clas attributes
            double tmpX = r * std::cos(angle);
            double tmpY = r * std::sin(angle);


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
        r=0.5;

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

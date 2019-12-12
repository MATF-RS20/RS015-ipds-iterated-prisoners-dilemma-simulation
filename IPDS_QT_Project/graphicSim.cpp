#define _USE_MATH_DEFINES


#include "graphicSim.hpp"
#include "food.h"
#include "graphics.h"
#include "specimen.h"
#include "simulation.h"
#include "estrategy.h"
#include <cmath>
#include <cstdlib>

static const double PI = 3.14159265358979323846264338327950288419717;
static const double TWO_PI = 2.0 * PI;

/*function that maps given angle to [0,2*PI]*/
static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
    {
        angle += TWO_PI;
    }

    while (angle > TWO_PI)
    {
        angle -= TWO_PI;
    }

    return angle;
}

graphicSim::graphicSim(int foodNo, std::vector<int> &specimenNoInfo)
    :Simulation(foodNo,specimenNoInfo)
{

    /*Initializes Simulation and by extension, all specimen instances*/
    unsigned strategyCount = strategy::COUNT;



    for(unsigned i=0; i<strategyCount; ++i)
    {
        unsigned long curSpecimenNo = this->m_specimen[i].size();

        for(unsigned long j=0; j<curSpecimenNo ; ++j)
        {
            this->m_specimen[i][j]->show();
        }

    }

    this->initializeFood(foodNo);

}
graphicSim::~graphicSim(){

}
void graphicSim::show()
{
    unsigned strategyCount = strategy::COUNT;
    for(unsigned i=0; i<strategyCount; ++i)
    {
        unsigned long curSpecimenNo = this->m_specimen[i].size();

        for(unsigned long j=0; j<curSpecimenNo ; ++j)
        {
            this->m_specimen[i][j]->show();
        }

    }
}

void graphicSim::addItems(QGraphicsScene& scene)
{
    for(auto stratVector : this->m_specimen)
    {
        for(auto tmpSpecimen : stratVector)
        {
            scene.addItem(tmpSpecimen.get());
        }
    }
}

void graphicSim::initializeFood(int foodNo)
{
    //TODO add global drawing center,scale to R
    double randa,randr;
    double centerX = -10.0;
    double centerY = -20.0;

    /*Generates random position inside a circle*/
    /*randr signifies the distance from the center, randa signifies the angle for the polar coordinates*/
    for(int i=0;i<foodNo; ++i)
    {
        //TODO clean up this blasphemous random number generation and pi representation
        //TODO tweak size of r to match window size


        randr = static_cast<double>(qrand())/RAND_MAX;
        double r = randr*sqrt(centerX*centerX+centerY*centerY);


        randa = static_cast<double>(qrand())/RAND_MAX;
        double tmpX = r * std::cos(randa*2*M_PI);
        double tmpY = r * std::sin(randa*2*M_PI);

        /*Adds the generated food to the appropriate attribute*/
        this->m_foodVector.emplace_back(tmpX,tmpY);
    }
}


//void graphicSim::moveSpecimen()
//{

//}



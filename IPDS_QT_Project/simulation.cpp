#include "simulation.h"

Simulation::Simulation(const unsigned foodNo, std::vector<unsigned> &specimenNoInfo)
    : m_foodNo(foodNo)
{
    m_specimenNo = std::accumulate(std::begin(specimenNoInfo), std::end(specimenNoInfo), 0);
    m_graphInfo.update(specimenNoInfo);

    int size = static_cast<int>(specimenNoInfo.size());
    for(int i = 0; i < size; i++){
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < specimenNoInfo[i]; j++)
        {
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
        }
    }

    initializeFood();

}

Simulation::Simulation(const Simulation& other)
{
    m_foodNo = other.m_foodNo;
    m_specimenNo = other.m_specimenNo;

    int size = static_cast<int>(other.m_specimen.size());

    for(int i = 0; i < size; i++)
    {
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < other.m_specimen[i].size() ; j++)
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
    }

    m_graphInfo = other.m_graphInfo;
    initializeFood();

}

Simulation& Simulation::operator=(const Simulation& other)
{
    m_foodNo = other.m_foodNo;
    m_specimenNo = other.m_specimenNo;
    m_graphInfo = other.m_graphInfo;

    int size = static_cast<int>(other.m_specimen.size());
    for(int i = 0; i < size; i++)
    {
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(unsigned j = 0; j < other.m_specimen[i].size() ; j++)
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
    }

    initializeFood();

    return *this;
}

void Simulation::initializeFood()
{
    // TODO add global drawing center,scale to R
    double randa, randr;
    double centerX = -10.0;
    double centerY = -20.0;

    // Generates random position inside a circle
    // randr signifies the distance from the center,
    // randa signifies the angle for the polar coordinates
    for(unsigned i = 0; i < m_foodNo; i++)
    {
        // TODO clean up this blasphemous random number generation and pi representation
        // TODO tweak size of r to match window size

        randr = static_cast<double>(qrand())/RAND_MAX;
        double r = randr * sqrt(centerX * centerX + centerY * centerY);

        randa = static_cast<double>(qrand())/RAND_MAX;
        double tmpX = r * std::cos(randa * 2 * M_PI);
        double tmpY = r * std::sin(randa * 2 * M_PI);

        /*Adds the generated food to the appropriate attribute*/
        m_foodsActive.emplace_back(tmpX, tmpY, i);
    }
}

std::shared_ptr<Specimen> Simulation::specimenFactory(strategy indicator)
{

    switch(indicator)
    {
    case (E_DOVE):
        return std::make_shared<Dove>();
    case (E_RANDOM):
        return std::make_shared<AllRandom>();
    case (E_HAWK):
        return std::make_shared<Hawk>();
    case (E_PAVLOV):
        return std::make_shared<Pavlov>();
    case (E_TITFORTAT):
        return std::make_shared<TitForTat>();
    case (E_TWOTITSFORTAT):
        return std::make_shared<TwoTitsForTat>();
    case (E_TITFORTWOTATS):
        return std::make_shared<TitForTwoTats>();
    default:
        return nullptr;
    }
}

unsigned Simulation::randomFoodPicker()
{
    // Obtaining random number from hardware
    std::random_device rd;

    // Mersenne Twister random number generator
    // https://en.wikipedia.org/wiki/Mersenne_Twister
    std::mt19937 eng(rd());

    /* Produces random int from a range where each
     * number from a range has equal likelihood to
     * be produced
     */
    std::uniform_int_distribution<> distr(m_foodsRndCounter, m_foodNo);

    return static_cast<unsigned>(distr(eng));
}

void Simulation::swapFoods(unsigned a, unsigned b)
{
    Food tmp = m_foodsActive[a];
    m_foodsActive[a] = m_foodsActive[b];
    m_foodsActive[b] = tmp;
}

void Simulation::assignFoods()
{
    unsigned assFood;
    m_foodsRndCounter = 0;

    for(unsigned i = 0; i < m_specimen.size(); i++)
    {
        for(unsigned j = 0; j < m_specimen[i].size() ; j++)
        {
            assFood = randomFoodPicker();
            m_foodsActive[assFood].addSpecimen(m_specimen[i][j]);
            m_foodsActive[assFood].increasePresent();
            if(m_foodsActive[assFood].numPresent() == 2)
            {
                swapFoods(m_foodsRndCounter, assFood);
                m_foodsRndCounter++;
            }
        }
    }

    std::sort(std::begin(m_foodsActive), std::end(m_foodsActive),
              [](const Food &a, const Food &b)
                {return a.m_ID > b.m_ID;
                });

}

void Simulation::clearAssignedFoods()
{
    for(unsigned i = 0; i < m_foodNo; i++)
        m_foodsActive[i].releaseSpecimen();
}

void Simulation::simulate()
{

}

void Simulation::playRound()
{

}

void Simulation::log()
{

}

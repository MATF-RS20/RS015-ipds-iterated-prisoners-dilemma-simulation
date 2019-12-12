#include "simulation.h"
#include "strategiesheaders.h"

#include <algorithm>
#include <memory>

Simulation::Simulation(const int foodNo, std::vector<int> &specimenNoInfo)
    : m_foodNo(foodNo)
{
    m_specimenNo = std::accumulate(std::begin(specimenNoInfo), std::end(specimenNoInfo), 0);
    m_graphInfo.update(specimenNoInfo);

    int size = static_cast<int>(specimenNoInfo.size());
    for(int i=0; i<size; i++){
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < specimenNoInfo[i]; j++)
        {
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
        }
    }

    m_graphInfo.update(specimenNoInfo);
}


Simulation::Simulation(const Simulation& other)
{
//    this->m_specimenNo = other.m_specimenNo;
//    this->m_foodNo = other.m_foodNo;
//    int numOfStrats = other.m_specimen.size();
//    for(int i=0; i<numOfStrats ; ++i)
//    {

//        for(int j = 0; j < ; j++)
//        {
//            m_specimen[i].push_back(specimenFactory(i));
//        }
//    }


}
Simulation& Simulation::operator=(const Simulation& other)
{

}

std::shared_ptr<Specimen> Simulation::specimenFactory(strategy indicator)
{
    std::shared_ptr<Specimen> tmpVal(nullptr);

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


void Simulation::simulate()
{

}

void Simulation::playRound()
{

}

void Simulation::log()
{

}

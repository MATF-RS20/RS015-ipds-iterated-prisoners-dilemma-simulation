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
    for(int i = 0; i < size; i++){
        m_specimen.push_back(std::vector<std::shared_ptr<Specimen>>());
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < specimenNoInfo[i]; j++)
        {
            m_specimen[i].push_back(specimenFactory(static_cast<strategy>(i)));
        }
    }

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

    return *this;
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


void Simulation::simulate()
{

}

void Simulation::playRound()
{

}

void Simulation::log()
{

}

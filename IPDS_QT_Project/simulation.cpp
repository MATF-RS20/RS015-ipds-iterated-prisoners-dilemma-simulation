#include "simulation.h"

Simulation::Simulation(int foodNo, std::vector<std::vector<Specimen*>> &specimen, int specimenNo, std::vector<std::vector<int>> &graphInfo)
    : m_foodNo(foodNo), m_specimen(specimen), m_specimenNo(specimenNo), m_graphInfo(graphInfo)
{}

Simulation::Simulation(int foodNo, std::vector<std::vector<Specimen*>> &specimen, std::vector<std::vector<int>> &graphInfo)
    : m_foodNo(foodNo), m_specimen(specimen), m_specimenNo(0), m_graphInfo(graphInfo)
{
    for(std::vector<Specimen*> v : specimen)
    {
        m_specimenNo += v.size();
    }
}

Simulation::~Simulation()
{}

void Simulation::simulate()
{

}

void Simulation::playRound()
{

}

void Simulation::log()
{

}

#include "simulation.h"
#include <algorithm>
#include <thread>

Simulation::Simulation(const int foodNo, std::vector<int> &specimenNoInfo)
    : m_foodNo(foodNo)
{
    m_specimenNo = std::accumulate(std::begin(specimenNoInfo), std::end(specimenNoInfo), 0);
    m_graphInfo.push_back(specimenNoInfo);

    // TODO: implement creating objects, possibly in different threads?

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

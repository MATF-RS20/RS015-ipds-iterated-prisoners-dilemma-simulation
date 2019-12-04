#include "simulation.h"

Simulation::Simulation(int foodNo, std::vector<std::vector<Specimen*>> &specimen, int specimenNo, std::vector<SimState> &graphInfo)
    : m_foodNo(foodNo), m_specimen(specimen), m_specimenNo(specimenNo), m_graphInfo(graphInfo)
{}

Simulation::Simulation() = default;

#ifndef SIMULATION_H
#define SIMULATION_H

#include "specimen.h"
#include "simstate.h"
#include "estrategy.h"

class Simulation
{
public:
    Simulation(int foodNo, std::vector<std::vector<Specimen*>> &specimen, int specimenNo, std::vector<SimState> &graphInfo);
    Simulation();


private:
    // Number of foods used in that exact simulation
    int m_foodNo;

    /*
     * Matrix of Specimen objects that are currently
     * active in the Simulation.
     * Use estrategy enum to access particular row
     * that represent Specimen of certain kind
     *
     * Example:
     * m_specimen[Dove][0]
     *
     */
    std::vector<std::vector<Specimen*>> m_specimen;

    // Keeps track of number of all specimen
    int m_specimenNo;

    /* ????
     */
    std::vector<SimState> m_graphInfo;
};

#endif // SIMULATION_H

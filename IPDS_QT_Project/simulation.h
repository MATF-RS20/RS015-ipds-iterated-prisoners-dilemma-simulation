#include "specimen.h"
#include "simstate.h"
#include "estrategy.h"

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation
{
public:
    // Case: accepts a number of intended specimen at the beggining
    Simulation(int foodNo, std::vector<std::vector<Specimen*>> &specimen, int specimenNo, std::vector<std::vector<int>> &graphInfo);
    // Case: manually counts specimen
    Simulation(int foodNo, std::vector<std::vector<Specimen*>> &specimen, std::vector<std::vector<int>> &graphInfo);
    ~Simulation();

    void simulate();
    void playRound();
    void log();

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
    std::vector<std::vector<int>> m_graphInfo;
};

#endif // SIMULATION_H

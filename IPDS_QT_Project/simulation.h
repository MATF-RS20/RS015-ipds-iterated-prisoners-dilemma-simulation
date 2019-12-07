#include "specimen.h"
#include "estrategy.h"
#include <memory>

#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation
{
public:

    /* To create a simulation you only need to give it food
     * number and vector of numbers of all different specimen
     *
     * e.g.:
     * specimenNoInfo[E_DOVE] returns the initial number of
     * dove specimen, where E_DOVE is enum from estrategy.h
     *
     * Initializing other attributes is encapsulated
     *
     */
    Simulation(int foodNo, std::vector<int> &specimenNoInfo);
    ~Simulation();

    /* Simple implementation of a famous design pattern:
     * Factory Method
     *
     * Method accepts indicator and decides which object to
     * create
     */
    std::shared_ptr<Specimen> specimenFactory(int indicator);


    void simulate();
    void playRound();
    void log();

private:
    // Number of foods used in that exact simulation
    const int m_foodNo;

    /* Matrix of pointers to Specimen objects that are
     * currently active in the Simulation.
     * Use estrategy enum to access particular row
     * that represent Specimen of certain kind
     *
     * Example:
     * m_specimen[Dove][0]
     *
     */
    std::vector<std::vector<std::shared_ptr<Specimen>>> m_specimen;

    // Keeps track of number of all specimen
    int m_specimenNo;

    /* Keeps info on all previous rounds and number
     * of each type of specimen at that moment
     *
     */
    std::vector<std::vector<int>> m_graphInfo;
};

#endif // SIMULATION_H

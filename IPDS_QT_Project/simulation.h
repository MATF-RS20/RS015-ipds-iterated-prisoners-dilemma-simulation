#include "specimen.h"
#include "estrategy.h"
#include "statehistory.h"
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

    /*Vlada here, pls no kill me*/
    virtual ~Simulation() = default;
    Simulation(const Simulation& other);
    Simulation& operator=(const Simulation& other);
    /* Simple implementation of a famous design pattern:
     * Factory Method
     *
     * Method accepts indicator and decides which object to
     * create
     */
    std::shared_ptr<Specimen> specimenFactory(strategy indicator);

    void simulate();
    void playRound();
    void log();

protected:
    // Number of foods used in that exact simulation
    int m_foodNo;

    /* Matrix of pointers to all the active specimen
     * on the current field.
     *
     * Each row represents group of specimen of the same
     * kind, we know which is which by using estrategy
     *
     * shared_ptr is used for the easier memory management
     * i might change that later to unique_ptr if needed
     *
     */
    std::vector<std::vector<std::shared_ptr<Specimen>>> m_specimen;

    // Keeps track of number of all specimen
    int m_specimenNo;

    /* Keeps info on all previous rounds and number
     * of each type of specimen at that moment
     */
    StateHistory m_graphInfo;
};

#endif // SIMULATION_H

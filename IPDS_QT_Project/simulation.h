#define _USE_MATH_DEFINES

#include "specimen.h"
#include "statehistory.h"
#include "strategiesheaders.h"
#include "estrategy.h"
#include "food.h"
#include <memory>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <random>

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
    Simulation(unsigned foodNo, std::vector<unsigned> &specimenNoInfo);

    /*Vlada here, pls no kill me*/
    virtual ~Simulation() = default;
    Simulation(const Simulation& other);
    Simulation& operator=(const Simulation& other);

    void initializeFood();
    unsigned randomFoodPicker();

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

    const StateHistory graphInfo() const{
        return m_graphInfo;
    }

protected:
    // Number of foods used in that exact simulation
    unsigned m_foodNo;
    std::vector<Food> m_foodsActive;

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
    unsigned m_specimenNo;

    /* Keeps info on all previous rounds and number
     * of each type of specimen at that moment
     */
    StateHistory m_graphInfo;
    unsigned m_foodsRndCounter = 0;
};

#endif // SIMULATION_H

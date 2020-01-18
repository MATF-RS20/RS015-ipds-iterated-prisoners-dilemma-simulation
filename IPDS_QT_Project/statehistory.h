#include <vector>
#include "estrategy.h"

#ifndef STATEHISTORY_H
#define STATEHISTORY_H

/* StateHistory is used to record info about iterations of a
 * simulation. Its primary purpose is to be utilized for drawing
 * the graph. The information recorded is the number of Specimen
 * for each strategy in each iteration. */

class StateHistory
{
public:
    StateHistory();
    StateHistory(const StateHistory &other);

    StateHistory& operator=(const StateHistory &other);

    /* Appends the vector containing the no of specimen of each
     * strategy as the last iteration. */
    void update(std::vector<unsigned> iterationInfo);

    /* Returns iterationNo-th iteration data. */
    std::vector<unsigned> getIteration(unsigned iterationNo) const;

    /* Get the vector of number of Specimen of a certain strategy
     * in every iteration since the beginning. */
    std::vector<unsigned> getByStrategy(strategy s) const;

    /* Get the entire history. */
    std::vector<std::vector<unsigned>> getAllIterations();

    /* Getter for number of iterations. */
    int iterationNo() const;

protected:
    std::vector<std::vector<unsigned>> m_innerGraphInfo;
    int m_iterationNo = 0;
};

#endif // STATEHISTORY_H

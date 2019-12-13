#include <vector>
#include "estrategy.h"

#ifndef STATEHISTORY_H
#define STATEHISTORY_H


class StateHistory
{
public:
    StateHistory();
    StateHistory(const StateHistory &other);

    StateHistory& operator=(const StateHistory &other);

    void update(std::vector<unsigned> iterationInfo);

    std::vector<unsigned> getIteration(unsigned iterationNo) const;

    std::vector<unsigned> getByStrategy(strategy s) const;

    std::vector<std::vector<unsigned>> getAllIterations();

    int iterationNo() const;

protected:
    std::vector<std::vector<unsigned>> m_innerGraphInfo;
    int m_iterationNo = 0;
};

#endif // STATEHISTORY_H

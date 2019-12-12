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

    void update(std::vector<int> iterationInfo);

    std::vector<int> getIteration(unsigned iterationNo) const;

    std::vector<int> getByStrategy(strategy s) const;

    std::vector<std::vector<int>> getAllIterations();

protected:
    std::vector<std::vector<int>> m_innerGraphInfo;
};

#endif // STATEHISTORY_H

#include <vector>
#include "estrategy.h"

#ifndef STATEHISTORY_H
#define STATEHISTORY_H


class StateHistory
{
public:
    StateHistory();

    void update(std::vector<int> iterationInfo);

    std::vector<int> getIteration(unsigned iterationNo) const;

    std::vector<int> getByStrategy(strategy s) const;

protected:
    std::vector<std::vector<int> > graphInfo;
};

#endif // STATEHISTORY_H

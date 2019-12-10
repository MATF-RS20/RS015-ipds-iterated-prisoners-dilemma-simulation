#include <vector>

#ifndef STATEHISTORY_H
#define STATEHISTORY_H


class StateHistory
{
public:
    StateHistory();

    void update(std::vector<int> iterationInfo);

    std::vector<int> getIteration(unsigned iterationNo);

protected:
    std::vector<std::vector<int> > graphInfo;
};

#endif // STATEHISTORY_H

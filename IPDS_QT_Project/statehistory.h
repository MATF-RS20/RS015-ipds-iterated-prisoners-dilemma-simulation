#include <vector>

#ifndef STATEHISTORY_H
#define STATEHISTORY_H


class StateHistory
{
public:
    StateHistory();
    StateHistory(const StateHistory &other);

    StateHistory& operator=(const StateHistory &other);

    void update(std::vector<int> iterationInfo);

    std::vector<int> getIteration(unsigned iterationNo);

    std::vector<std::vector<int>> getAllIterations();

protected:
    std::vector<std::vector<int>> m_innerGraphInfo;
};

#endif // STATEHISTORY_H

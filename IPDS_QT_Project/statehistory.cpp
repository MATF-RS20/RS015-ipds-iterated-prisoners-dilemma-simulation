#include "statehistory.h"

StateHistory::StateHistory() {}

StateHistory::StateHistory(const StateHistory &other) {}

StateHistory& StateHistory::operator=(const StateHistory &other)
{
    m_innerGraphInfo = other.m_innerGraphInfo;
    return *this;
}

void StateHistory::update(std::vector<int> iterationInfo)
{
    m_innerGraphInfo.push_back(iterationInfo);
}

std::vector<int> StateHistory::getIteration(unsigned iterationNo)
{
    return m_innerGraphInfo[iterationNo];
}

std::vector<int> StateHistory::getIteration(unsigned iterationNo) const {
    return graphInfo[iterationNo];
}

std::vector<std::vector<int>> StateHistory::getAllIterations()
{
    return m_innerGraphInfo;
}


std::vector<int> StateHistory::getByStrategy(strategy s) const{
    std::vector<int> res;
    for(auto iteration : graphInfo){
        res.push_back(iteration[static_cast<int>(s)]);
    }
    return res;
}

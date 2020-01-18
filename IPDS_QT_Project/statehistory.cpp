#include "statehistory.h"

StateHistory::StateHistory() {}

StateHistory::StateHistory(const StateHistory &other)
{
    this->m_iterationNo = other.m_iterationNo;
    this->m_innerGraphInfo = other.m_innerGraphInfo;

}

StateHistory& StateHistory::operator=(const StateHistory &other)
{
    m_innerGraphInfo = other.m_innerGraphInfo;
    return *this;
}

void StateHistory::update(std::vector<unsigned> iterationInfo)
{
    m_innerGraphInfo.push_back(iterationInfo);
    m_iterationNo++;
}

std::vector<unsigned> StateHistory::getIteration(unsigned iterationNo) const
{
    if(iterationNo < m_innerGraphInfo.size())
        return m_innerGraphInfo[iterationNo];
    else
        return std::vector<unsigned>();
}

std::vector<std::vector<unsigned>> StateHistory::getAllIterations()
{
    return m_innerGraphInfo;
}

std::vector<unsigned> StateHistory::getByStrategy(strategy s) const {
    std::vector<unsigned> res;
    for(auto iteration : m_innerGraphInfo){
        res.push_back(iteration[static_cast<int>(s)]);
    }
    return res;
}

int StateHistory::iterationNo() const {
    return m_iterationNo;
}

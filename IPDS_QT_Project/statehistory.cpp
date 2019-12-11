#include "statehistory.h"

StateHistory::StateHistory() {}

void StateHistory::update(std::vector<int> iterationInfo){
    graphInfo.push_back(iterationInfo);
}

std::vector<int> StateHistory::getIteration(unsigned iterationNo){
    return graphInfo[iterationNo];
}

std::vector<std::vector<int>> StateHistory::getAllIterations()
{
    return graphInfo;
}

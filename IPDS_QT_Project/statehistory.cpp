#include "statehistory.h"

StateHistory::StateHistory() {}

void StateHistory::update(std::vector<int> iterationInfo){
    graphInfo.push_back(iterationInfo);
}

std::vector<int> StateHistory::getIteration(unsigned iterationNo) const{
    return graphInfo[iterationNo];
}


std::vector<int> StateHistory::getByStrategy(strategy s) const{
    std::vector<int> res;
    for(auto iteration : graphInfo){
        res.push_back(iteration[static_cast<int>(s)]);
    }
    return res;
}

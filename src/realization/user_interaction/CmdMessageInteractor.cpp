#include "../../../include/realization/user_interaction/CmdMessageInteractor.hpp"

CmdMessageInteractor::CmdMessageInteractor(
                            std::shared_ptr<AbstractMessageStorage> msgStorage)
                                        : AbstractMessageInteractor(msgStorage) {
}

void CmdMessageInteractor::printInfo(std::shared_ptr<Conclusions> conclusions) {
    std::cout << this->messagesStorage.get()->getKnownStatesMsg() << std::endl;
    this->printStates(*(conclusions.get()->getKnown()));
    std::cout << this->messagesStorage.get()->getUnknownStatesMsg() << std::endl;
    this->printStates(*(conclusions.get()->getUnknown()));
}

void CmdMessageInteractor::printStates(std::list<AbstractState> &states) {
    for (auto itState = states.begin(); itState != states.end(); ++itState) {
        std::cout << this->messagesStorage.get()->getStateMsg(*itState) << std::endl;
    }
    std::cout << std::endl;
}

void CmdMessageInteractor::printIterationNumber(int iteration) {
    std::cout << this->messagesStorage.get()->getIterNumMsg(iteration) << std::endl;
}

void CmdMessageInteractor::printRuleNotExcluded() {
    std::cout << this->messagesStorage.get()->getRuleNotExcluded() << std::endl;
}

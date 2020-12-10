#include "../../../include/realization/user_interaction/CmdMessageInteractor.hpp"

CmdMessageInteractor::CmdMessageInteractor(
                            std::shared_ptr<AbstractMessageStorage> msgStorage)
                                        : AbstractMessageInteractor(msgStorage) {
}

void CmdMessageInteractor::printInfo(std::shared_ptr<Conclusions> conclusions) {
    std::cout << this->messagesStorage->getKnownStatesMsg() << std::endl;
    this->printStates(*(conclusions->getKnown()));
    std::cout << this->messagesStorage->getUnknownStatesMsg() << std::endl;
    this->printStates(*(conclusions->getUnknown()));
}

void CmdMessageInteractor::printStates(std::vector<AbstractState> &states) {
    for (auto itState = states.begin(); itState != states.end(); ++itState) {
        std::cout << this->messagesStorage->getStateMsg(*itState) << std::endl;
    }
    std::cout << std::endl;
}

void CmdMessageInteractor::printIterationNumber(int iteration) {
    std::cout << this->messagesStorage->getIterNumMsg(iteration) << std::endl;
}

void CmdMessageInteractor::printRuleNotExcluded() {
    std::cout << this->messagesStorage->getRuleNotExcluded() << std::endl;
}

void CmdMessageInteractor::printSomeStatesNotDefined() {
    std::cout << this->messagesStorage->getSomeStatesNotDefined() << std::endl;
}

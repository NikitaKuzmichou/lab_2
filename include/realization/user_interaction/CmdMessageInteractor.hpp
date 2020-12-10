#ifndef CMD_MESSAGE_INTERACTOR
#define CMD_MESSAGE_INTERACTOR

#include "../../ai/interaction/AbstractMessageInteractor.hpp"

class CmdMessageInteractor : public AbstractMessageInteractor {
private:
	void printStates(std::vector<AbstractState> &states);
public:
	CmdMessageInteractor(std::shared_ptr<AbstractMessageStorage> msgStorage);
	virtual void printInfo(std::shared_ptr<Conclusions> conclusions) override;
	virtual void printIterationNumber(int i = 1) override;
	virtual void printRuleNotExcluded() override;
	virtual void printSomeStatesNotDefined() override;
};

#endif // !CMD_MESSAGE_INTERACTOR

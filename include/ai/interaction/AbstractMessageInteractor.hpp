#ifndef ABSTRACT_MESSAGE_INTERACTOR
#define ABSTRACT_MESSAGE_INTERACTOR

#include "../logic_kernel/Conclusions.hpp"
#include "msg_storage/AbstractMessageStorage.hpp"

class AbstractMessageInteractor {
protected:
	std::shared_ptr<AbstractMessageStorage> messagesStorage;
public:
	AbstractMessageInteractor(std::shared_ptr<AbstractMessageStorage> messagesStorage);
	~AbstractMessageInteractor();
	virtual void printInfo(std::shared_ptr<Conclusions> conclusions) = 0;
	virtual void printIterationNumber(int i = 0) = 0;
	virtual void printRuleNotExcluded() = 0;
};

#endif // !ABSTRACT_MESSAGE_INTERACTOR

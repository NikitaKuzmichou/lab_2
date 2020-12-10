#ifndef ABSTRACT_MESSAGE_STORAGE
#define ABSTRACT_MESSAGE_STORAGE

#include "../../states/AbstractState.hpp"
#include <string>

class AbstractMessageStorage {
public:
	virtual std::string getStateMsg(AbstractState state) = 0;
	virtual std::string getIterNumMsg(int number) = 0;
	virtual std::string getRuleNotExcluded() = 0;
	virtual std::string getKnownStatesMsg() = 0;
	virtual std::string getUnknownStatesMsg() = 0;
	virtual std::string getSomeStatesNotDefined() = 0;
};

#endif // !ABSTRACT_MESSAGE_STORAGE

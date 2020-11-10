#ifndef ABSTRACT_REQUEST_RESOLVER
#define ABSTRACT_REQUEST_RESOLVER

#include <iostream>
#include "../states/AbstractState.hpp"

class AbstractResponseInteractor {
private:
	int readedValue;
protected:
	unsigned int stateId;
public:
	AbstractResponseInteractor();
	std::shared_ptr<AbstractState> getReadedState();
	virtual std::shared_ptr<AbstractState> readState(unsigned int id) = 0;
	friend std::istream& operator>> (std::istream& is, AbstractResponseInteractor* urr);
};

#endif // !USER_REQUEST_RESOLVER

#ifndef ABSTRACT_REQUEST_GENERATOR
#define ABSTRACT_REQUEST_GENERATOR

#include "msg_storage/AbstractRequestsStorage.hpp"
#include <string>
#include <iostream>

class AbstractRequestInteractor {
protected:
	std::shared_ptr<AbstractRequestsStorage> reqStorage;
public:
	AbstractRequestInteractor(std::shared_ptr<AbstractRequestsStorage> reqStorage);
	~AbstractRequestInteractor();
	void setRequestStorage(std::shared_ptr<AbstractRequestsStorage> reqStorage);
	virtual void printRequest(unsigned int id) = 0;
};

#endif // !ABSTRACT_REQUEST_GENERATOR

#ifndef ABSTRACT_REQUESTS_STORAGE
#define ABSTRACT_REQUESTS_STORAGE

#include <string>

class AbstractRequestsStorage {
public:
	virtual std::string getRequest(unsigned int id) = 0;
};

#endif // !ABSTRACT_REQUEST_STORAGE

#ifndef CMD_REQUESTS_STORAGE
#define CMD_REQUESTS_STORAGE

#include "../../../ai/interaction/msg_storage/AbstractRequestsStorage.hpp"

class CmdRequestsStorage : public AbstractRequestsStorage {
public:
	virtual std::string getRequest(unsigned int id) override;
};

#endif // !CMD_REQUSTS_STORAGE

#ifndef CMD_REQUEST_INTERACTOR
#define CMD_REQUEST_INTERACTOR

#include "../../ai/interaction/AbstractRequestInteractor.hpp"

class CmdRequestInteractor : public AbstractRequestInteractor {
public:
	CmdRequestInteractor(std::shared_ptr<AbstractRequestsStorage> reqStorage);
	virtual void printRequest(unsigned int id) override;
};

#endif // !CMD_REQUEST_INTERACTOR

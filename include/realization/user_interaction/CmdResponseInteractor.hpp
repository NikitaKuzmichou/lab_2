#ifndef CMD_RESPONSE_INTERACTOR
#define CMD_RESPONSE_INTERACTOR

#include "../../ai/interaction/AbstractResponseInteractor.hpp"

class CmdResponseInteractor : public AbstractResponseInteractor {
public:
	CmdResponseInteractor();
	virtual std::shared_ptr<AbstractState> readState(unsigned int id) override;
};

#endif // !CMD_RESPONSE_INTERACTOR

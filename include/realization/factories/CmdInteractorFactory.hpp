#ifndef CMD_INTERACTOR_FACTORY
#define CMD_INTERACTOR_FACTORY

#include "../../ai/factories/interaction/AbstractInteractorFactory.hpp"

class CmdInteractorFactory : protected AbstractInteractorFactory {
private:
	CmdInteractorFactory();
public:
	static AbstractInteractorFactory* getInstance();
	virtual std::shared_ptr<AbstractRequestInteractor> getRequestInteractor() override;
	virtual std::shared_ptr<AbstractResponseInteractor> getResponseInteractor() override;
	virtual std::shared_ptr<AbstractMessageInteractor> getMessageInteractor() override;
};


#endif // !CMD_INTERACTOR_FACTORY

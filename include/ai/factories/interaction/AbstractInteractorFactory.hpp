#ifndef ABSTRACT_INTERACTOR_FACTORY
#define ABSTRACT_INTERACTOR_FACTORY

#include <memory>
#include "../../interaction/AbstractRequestInteractor.hpp"
#include "../../interaction/AbstractResponseInteractor.hpp"
#include "../../interaction/AbstractMessageInteractor.hpp"

class AbstractInteractorFactory {
protected:
	static AbstractInteractorFactory* instance;
public:
	static AbstractInteractorFactory* getInstance();
	virtual std::shared_ptr<AbstractRequestInteractor> getRequestInteractor() = 0;
	virtual std::shared_ptr<AbstractResponseInteractor> getResponseInteractor() = 0;
	virtual std::shared_ptr<AbstractMessageInteractor> getMessageInteractor() = 0;
};

#endif // !ABSTRACT_INTERACTOR_FACTORY

#ifndef FACTORIES_FACTORY
#define FACTORIES_FACTORY

#include <memory>
#include "interaction/AbstractInteractorFactory.hpp"

class FactoriesFactory {
private:
	static std::shared_ptr<FactoriesFactory> instance;
	AbstractInteractorFactory* interactorInstance;
public:
	static std::shared_ptr<FactoriesFactory> getInstance();
	void setInteractorFactoryInstance(AbstractInteractorFactory*);
	AbstractInteractorFactory* getInteractorFactoryInstance();
};

#endif //!FACTORIES_FACTORY
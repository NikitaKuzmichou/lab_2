#include "../../../include/ai/factories/FactoriesFactory.hpp"

std::shared_ptr<FactoriesFactory> FactoriesFactory::instance = nullptr;

std::shared_ptr<FactoriesFactory> FactoriesFactory::getInstance() {
	if (!instance) {
		instance = std::make_shared<FactoriesFactory>();
	}
	return instance;
}

void FactoriesFactory::setInteractorFactoryInstance(
	              AbstractInteractorFactory* instance) {
	this->interactorInstance = instance;
}


AbstractInteractorFactory* FactoriesFactory::getInteractorFactoryInstance() {
	return this->interactorInstance;
}

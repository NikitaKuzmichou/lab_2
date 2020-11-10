#include "../../../../include/ai/factories/interaction/AbstractInteractorFactory.hpp"

AbstractInteractorFactory* AbstractInteractorFactory::instance = nullptr;

AbstractInteractorFactory* AbstractInteractorFactory::getInstance() {
	return instance;
}
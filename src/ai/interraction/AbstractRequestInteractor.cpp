#include "../../../include/ai/interaction/AbstractRequestInteractor.hpp"

AbstractRequestInteractor::AbstractRequestInteractor(
	                      std::shared_ptr<AbstractRequestsStorage> reqStorage) {
	this->reqStorage = reqStorage;
}

AbstractRequestInteractor::~AbstractRequestInteractor() {
	this->reqStorage.reset();
}

void AbstractRequestInteractor::setRequestStorage(
	                         std::shared_ptr<AbstractRequestsStorage> reqStorage) {
	this->reqStorage = reqStorage;
}

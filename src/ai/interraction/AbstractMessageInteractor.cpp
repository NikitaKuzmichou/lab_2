#include "../../../include/ai/interaction/AbstractMessageInteractor.hpp"

AbstractMessageInteractor::AbstractMessageInteractor(
	                         std::shared_ptr<AbstractMessageStorage> msgStorage) {
	this->messagesStorage = msgStorage;
}

AbstractMessageInteractor::~AbstractMessageInteractor() {
	this->messagesStorage.reset();
}

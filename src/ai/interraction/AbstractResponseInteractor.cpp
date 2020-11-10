#include "../../../include/ai/interaction/AbstractResponseInteractor.hpp"

AbstractResponseInteractor::AbstractResponseInteractor() {
	this->stateId = 0;
	this->readedValue = -1;
}

std::shared_ptr<AbstractState> AbstractResponseInteractor::getReadedState() {
	return std::make_shared<AbstractState>(this->stateId, this->readedValue);
}

std::istream& operator>> (std::istream& is, AbstractResponseInteractor* urr) {
	is >> urr->readedValue;
	return is;
}

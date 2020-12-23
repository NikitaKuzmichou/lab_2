#include "../../../include/ai/interaction/AbstractResponseInteractor.hpp"

AbstractResponseInteractor::AbstractResponseInteractor() {
	this->stateId = 0;
	this->readedValue = -1;
}

std::shared_ptr<AbstractState> AbstractResponseInteractor::getReadedState() {
	auto state = std::make_shared<AbstractState>(this->stateId, this->readedValue);
	state->setInitType(InitType::FROM_USER);
	return state;
}

std::istream& operator>> (std::istream& is, AbstractResponseInteractor* urr) {
	is >> urr->readedValue;
	return is;
}

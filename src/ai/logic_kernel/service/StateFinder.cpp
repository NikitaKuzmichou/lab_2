#include "../../../../include/ai/logic_kernel/service/StateFinder.hpp"

StateFinder::StateFinder() {
	this->status = StateStatus::UNDEFINED;
}

StateStatus StateFinder::getStatus() {
	return this->status;
}

AbstractState StateFinder::getState() {
	return this->state;
}

StateStatus StateFinder::findState(std::vector<AbstractState>& knownStates, AbstractState& state) {
	this->state = state;
	for (auto& knownState : knownStates) {
		if (knownState.getId() == state.getId()) {
			if (knownState == state) {
				this->status = StateStatus::CONFIRMED;
			}
			else {
				this->status = StateStatus::DIVERGENCE;
			}
			return this->status;
		}
	}
	this->status = StateStatus::NOT_FOUND;
	return this->status;
}

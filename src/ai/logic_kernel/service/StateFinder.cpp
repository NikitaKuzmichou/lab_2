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

StateStatus StateFinder::findState(AbstractState& state, Rule rule) {
	this->state = state;
	auto stateId = state.getId();
	if (stateId == rule.getÑonsequence().get()->getId()) {
		this->status = StateStatus::DIVERGENCE;
		return this->status;
	}
	for (auto itRuleState = rule.getStates().get()->begin();
		itRuleState != rule.getStates().get()->end(); ++itRuleState) {
		auto ruleStateId = (*itRuleState).getId();
		if (stateId == ruleStateId) {
			if (state.getValue() == (*itRuleState).getValue()) {
				this->status = StateStatus::CONFIRMED;
			} else {
				this->status = StateStatus::DIVERGENCE;
			}
			return this->status;
		}
	}
	this->status = StateStatus::NOT_FOUND;
	return this->status;
}

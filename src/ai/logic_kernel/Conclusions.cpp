#include "../../../include/ai/logic_kernel/Conclusions.hpp"

Conclusions::Conclusions() {
	this->known = std::make_shared<std::vector<AbstractState>>();
	this->unknown = std::make_shared<std::vector<AbstractState>>();
}

Conclusions::Conclusions(std::shared_ptr<std::vector<AbstractState>> unknown) {
	this->known = std::make_shared<std::vector<AbstractState>>();
	this->unknown = unknown;
}

Conclusions::~Conclusions() {
	this->known.reset();
	this->unknown.reset();
}

void Conclusions::addKnownState(const AbstractState& state) {
	this->removeFromUnknownStates(state);
	if (!this->isAlreadyStored(state)) {
		this->known->push_back(state);
	}
}

std::shared_ptr<std::vector<AbstractState>> Conclusions::getKnown() {
	return this->known;
}


bool Conclusions::addUnknownState(const AbstractState& state) {
	if (this->isAlreadyStored(state)) {
		return false;
	}
	this->unknown->push_back(state);
	return true;
}

std::shared_ptr<std::vector<AbstractState>> Conclusions::getUnknown() {
	return this->unknown;
}

bool Conclusions::hasUnknownState() {
	return !this->unknown->empty();
}

bool Conclusions::isAlreadyStored(const AbstractState& state) {
	for (int i = 0; i < this->known->size(); ++i) {
		if (this->known->at(i).getId() == state.getId()) {
			return true;
		}
	}
	return false;
}

void Conclusions::removeFromUnknownStates(const AbstractState& state) {
	auto itState = std::find(this->unknown->begin(), 
		                                this->unknown->end(), state);
	if (itState != this->unknown->end()) {
		this->unknown->erase(itState);
	}
}

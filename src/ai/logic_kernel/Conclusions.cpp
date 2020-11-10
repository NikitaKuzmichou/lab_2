#include "../../../include/ai/logic_kernel/Conclusions.hpp"

Conclusions::Conclusions() {
	this->known = std::make_shared<std::list<AbstractState>>();
	this->unknown = std::make_shared<std::list<AbstractState>>();
	this->fresh = std::make_shared<std::list<AbstractState>>();
}

Conclusions::Conclusions(std::shared_ptr<std::list<AbstractState>> unknown) {
	this->known = std::make_shared<std::list<AbstractState>>();
	this->unknown = unknown;
	this->fresh = std::make_shared<std::list<AbstractState>>();
}

Conclusions::~Conclusions() {
	this->known.reset();
	this->unknown.reset();
	this->fresh.reset();
}

void Conclusions::addUserInput(const AbstractState& state) {
	this->removeFromUnknownStates(state);
	this->known.get()->push_back(state);
}

std::shared_ptr<std::list<AbstractState>> Conclusions::getKnown() {
	return this->known;
}


bool Conclusions::addUnknownState(const AbstractState& state) {
	if (this->isAlreadyStored(state)) {
		return false;
	}
	this->unknown.get()->push_back(state);
	return true;
}

std::shared_ptr<std::list<AbstractState>> Conclusions::getUnknown() {
	return this->unknown;
}

void Conclusions::addFreshState(const AbstractState& state) {
	this->removeFromUnknownStates(state);
	this->fresh.get()->push_back(state);
}

std::shared_ptr<std::list<AbstractState>> Conclusions::getFresh() {
	return this->fresh;
}

void Conclusions::updateKnownStates() {
	while (!this->fresh.get()->empty()) {
		this->known.get()->push_back(this->fresh.get()->front());
		this->fresh.get()->pop_front();
	}
}

bool Conclusions::hasUnknownState() {
	return !this->unknown.get()->empty();
}

bool Conclusions::isAlreadyStored(const AbstractState& state) {
	auto itState = std::find(this->known.get()->begin(),
		                                this->known.get()->end(), state);
	if (itState == this->known.get()->end()) {
		return true;
	}
	itState = std::find(this->fresh.get()->begin(),
		                                this->fresh.get()->end(), state);
	if (itState == this->fresh.get()->end()) {
		return true;
	}
	return false;
}

void Conclusions::removeFromUnknownStates(const AbstractState& state) {
	auto itState = std::find(this->unknown.get()->begin(), 
		                                this->unknown.get()->end(), state);
	this->unknown.get()->erase(itState);
}

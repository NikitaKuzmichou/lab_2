#include "../../../include/ai/knowledge_base/Rule.hpp"

Rule::Rule() {
	this->id = 0;
	this->consequence = nullptr;
	this->states = nullptr;
}

Rule::Rule(int id) {
	this->id;
	this->consequence = nullptr;
	this->states = nullptr;
}


Rule::Rule(int id, std::shared_ptr<boost::ptr_list<AbstractState>> states,
	                               std::shared_ptr<AbstractState> conclusion) {
	this->id = id;
	this->states = states;
	this->consequence = conclusion;
}

Rule::~Rule() {
	this->states.reset();
	this->consequence.reset();
}

void Rule::setId(unsigned int id) {
	this->id = id;
}

unsigned int Rule::getId() {
	return this->id;
}

void Rule::set—onsequence(std::shared_ptr<AbstractState> conclusion) {
	this->consequence = conclusion;
}

std::shared_ptr<AbstractState> Rule::get—onsequence() {
	return this->consequence;
}

void Rule::addState(AbstractState* state) {
	this->states.get()->push_back(state);
}

void Rule::setStates(std::shared_ptr<boost::ptr_list<AbstractState>> states) {
	this->states.reset();
	this->states = states;
}

std::shared_ptr<boost::ptr_list<AbstractState>> Rule::getStates() {
	return this->states;
}

bool operator== (const Rule& rule1, const Rule& rule2) {
	return rule1.id == rule2.id;
}

bool operator!= (const Rule& rule1, const Rule& rule2) {
	return !(rule1.id == rule2.id);
}

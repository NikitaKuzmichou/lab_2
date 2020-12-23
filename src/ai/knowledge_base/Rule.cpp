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


Rule::Rule(int id, const std::shared_ptr<std::vector<AbstractState>> states,
	               const std::shared_ptr<AbstractState> conclusion) {
	this->id = id;
	this->states = states;
	this->consequence = conclusion;
	this->consequence->setInitType(InitType::FROM_CONCLUSIONS);
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
	this->consequence->setInitType(InitType::FROM_CONCLUSIONS);
}

std::shared_ptr<AbstractState> Rule::getConsequence() {
	return this->consequence;
}

void Rule::addState(AbstractState &state) {
	this->states->push_back(state);
}

void Rule::setStates(std::shared_ptr<std::vector<AbstractState>> states) {
	this->states.reset();
	this->states = states;
}

std::shared_ptr<std::vector<AbstractState>> Rule::getStates() {
	return this->states;
}

bool operator== (const Rule& rule1, const Rule& rule2) {
	return rule1.id == rule2.id;
}

bool operator!= (const Rule& rule1, const Rule& rule2) {
	return !(rule1.id == rule2.id);
}

std::ostream& operator<< (std::ostream& os, const Rule& rule) {
	os << "{ \n id:" << rule.id << "\n states: {" << std::endl;
	for (int i = 0; i < rule.states->size(); ++i) {
		os << "   " << rule.states->at(i) << "   " << std::endl;
	}
	os << "  }" << std::endl;
	os << "consequence: { " << std::endl;
	os << "   [\n" << *(rule.consequence) << "   ]" << std::endl;
	os << "  }" << std::endl;
	return os;
}

#include "../../../include/ai/states/AbstractState.hpp"

AbstractState::AbstractState() {
	this->id = 0;
	this->value = 0;
	this->initialized = false;
	this->initType = InitType::UNDEFINED;
}

AbstractState::AbstractState(unsigned int id) {
	this->id = id;
	this->value = 0;
	this->initialized = false;
	this->initType = InitType::UNDEFINED;
}

AbstractState::AbstractState(unsigned int id, int value) {
	this->id = id;
	this->value = value;
	this->initialized = true;
	this->initType = InitType::UNDEFINED;
}

unsigned int AbstractState::getId() const {
	return this->id;
}

void AbstractState::setInitType(InitType initType) {
	this->initType = initType;
}

InitType AbstractState::getInitType() const {
	return this->initType;
}

int AbstractState::getValue() const {
	return this->value;
}

void AbstractState::setId(unsigned int id) {
	this->id = id;
}

void AbstractState::setValue(int value) {
	this->value = value;
	this->initialized = true;
}

bool AbstractState::compare(const AbstractState& value) {
	return (*this) == value;
}

bool AbstractState::isInitialized() {
	return this->initialized;
}

bool operator!= (const AbstractState& val1, const AbstractState& val2) {
	return !(val1 == val2);
}

bool operator== (const AbstractState& val1, const AbstractState& val2) {
	if (val1.initialized && val2.initialized) {
		return val1.id == val2.id && val1.value == val2.value;
	}
	else {
		return val1.id == val2.id;
	}
}

std::ostream& operator<< (std::ostream& os, const AbstractState& val) {
	os << "[" << val.id << "; " << val.value << "]" << std::endl;
	return os;
}

std::istream& operator>> (std::istream& is, AbstractState* val) {
	is >> val->value;
	return is;
}

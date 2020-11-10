#include "../../../include/ai/states/AbstractState.hpp"

AbstractState::AbstractState() {
	this->id = 0;
	this->value = 0;
	this->initialized = false;
}

AbstractState::AbstractState(unsigned int id) {
	this->id = id;
	this->value = 0;
	this->initialized = false;
}

AbstractState::AbstractState(unsigned int id, int value) {
	this->id = id;
	this->value = value;
	this->initialized = true;
}

unsigned int AbstractState::getId() {
	return this->id;
}

int AbstractState::getValue() {
	return this->value;
}

void AbstractState::setId(unsigned int id) {
	this->id = id;
}

void AbstractState::setValue(int value) {
	this->value = value;
	this->initialized = true;
}

bool AbstractState::compare(AbstractState* value) {
	return (*this) == *value;
}

bool AbstractState::isInitialized() {
	return this->initialized;
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

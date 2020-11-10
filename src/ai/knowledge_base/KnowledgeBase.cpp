#include "../../../include/ai/knowledge_base/KnowledgeBase.hpp"

KnowledgeBase::KnowledgeBase() {
	this->rules = std::make_shared<boost::ptr_list<Rule>>();
	this->excludedRules = std::make_shared<boost::ptr_list<Rule>>();
}

KnowledgeBase::KnowledgeBase(std::shared_ptr<boost::ptr_list<Rule>> rules) {
	this->rules = rules;
	this->excludedRules = std::make_shared<boost::ptr_list<Rule>>();
}

KnowledgeBase::~KnowledgeBase() {
	this->rules.reset();
	this->excludedRules.reset();
}

void KnowledgeBase::addRule(Rule* rule) {
	this->rules.get()->push_back(rule);
}

boost::ptr_list<Rule> KnowledgeBase::getRules() {
	return *(this->rules);
}

boost::ptr_list<Rule> KnowledgeBase::getExcludedRules() {
	return *(this->excludedRules);
}


bool KnowledgeBase::excludeRule(Rule rule) {
	auto iter = std::find(this->rules.get()->begin(), this->rules.get()->end(), rule);
	if (iter == this->rules.get()->end()) {
		return false;
	}
	auto erased = this->rules.get()->erase(iter);
	this->excludedRules.get()->push_back(&(*erased));
	return true;
}

bool KnowledgeBase::hasNotExcludedRules() {
	return this->rules.get()->empty();
}

bool KnowledgeBase::hasExcludedRules() {
	return this->excludedRules.get()->empty();
}

void KnowledgeBase::resetExcludedRules() {
	while (!this->excludedRules.get()->empty()) {
		this->rules.get()->push_back(this->excludedRules.get()->pop_front().get());
	}
}

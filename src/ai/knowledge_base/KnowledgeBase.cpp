#include "../../../include/ai/knowledge_base/KnowledgeBase.hpp"

KnowledgeBase::KnowledgeBase() {
	this->rules = std::make_shared<std::list<Rule>>();
	this->excludedRules = std::make_shared<std::list<Rule>>();
}

KnowledgeBase::KnowledgeBase(const std::shared_ptr<std::list<Rule>> &rules) {
	this->rules = rules;
	this->excludedRules = std::make_shared<std::list<Rule>>();
}

KnowledgeBase::~KnowledgeBase() {
	this->rules.reset();
	this->excludedRules.reset();
}

void KnowledgeBase::addRule(Rule &rule) {
	this->rules.get()->push_back(rule);
}

std::shared_ptr<std::list<Rule>> KnowledgeBase::getRules() {
	return this->rules;
}

std::shared_ptr<std::list<Rule>> KnowledgeBase::getExcludedRules() {
	return this->excludedRules;
}


bool KnowledgeBase::excludeRule(const Rule &rule) {
	auto iter = std::find(this->rules.get()->begin(), this->rules.get()->end(), rule);
	if (iter == this->rules.get()->end()) {
		return false;
	}
	auto erased = this->rules.get()->erase(iter);
	this->excludedRules.get()->push_back(*erased);
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
		this->rules.get()->push_back(this->excludedRules.get()->front());
		this->excludedRules.get()->pop_front();
	}
}

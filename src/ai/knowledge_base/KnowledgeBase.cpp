#include "../../../include/ai/knowledge_base/KnowledgeBase.hpp"

KnowledgeBase::KnowledgeBase() {
	this->rules = std::make_shared<std::vector<Rule>>();
	this->excludedRules = std::make_shared<std::vector<Rule>>();
}

KnowledgeBase::KnowledgeBase(const std::shared_ptr<std::vector<Rule>> &rules) {
	this->rules = rules;
	this->excludedRules = std::make_shared<std::vector<Rule>>();
}

KnowledgeBase::~KnowledgeBase() {
	this->rules.reset();
	this->excludedRules.reset();
}

void KnowledgeBase::addRule(Rule &rule) {
	this->rules->push_back(rule);
}

std::shared_ptr<std::vector<Rule>> KnowledgeBase::getRules() {
	return this->rules;
}

std::shared_ptr<std::vector<Rule>> KnowledgeBase::getExcludedRules() {
	return this->excludedRules;
}


bool KnowledgeBase::excludeRule(const Rule &rule) {
	auto iter = std::find(this->rules->begin(), this->rules->end(), rule);
	if (iter == this->rules->end()) {
		return false;
	}
	this->excludedRules->push_back(*iter);
	this->rules->erase(iter);
	return true;
}

bool KnowledgeBase::hasNotExcludedRules() {
	return !this->rules->empty();
}

bool KnowledgeBase::hasExcludedRules() {
	return this->excludedRules->empty();
}

void KnowledgeBase::resetExcludedRules() {
	while (!this->excludedRules->empty()) {
		this->rules->push_back(this->excludedRules->back());
		this->excludedRules->pop_back();
	}
}

#ifndef KNOWLEDGE_BASE
#define KNOWLEDGE_BASE

#include "Rule.hpp"
#include <list>

class KnowledgeBase {
private:
	std::shared_ptr<std::list<Rule>> rules;
	std::shared_ptr<std::list<Rule>> excludedRules;
public:
	KnowledgeBase();
	KnowledgeBase(const std::shared_ptr<std::list<Rule>> &rules);
	~KnowledgeBase();
	void addRule(Rule &rule);
	std::shared_ptr<std::list<Rule>> getRules();
	std::shared_ptr<std::list<Rule>> getExcludedRules();
	bool excludeRule(const Rule &rule);
	bool hasNotExcludedRules();
	bool hasExcludedRules();
	void resetExcludedRules();
};

#endif // !KNOWLEDGE_BASE

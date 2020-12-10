#ifndef KNOWLEDGE_BASE
#define KNOWLEDGE_BASE

#include "Rule.hpp"
#include <vector>

class KnowledgeBase {
private:
	std::shared_ptr<std::vector<Rule>> rules;
	std::shared_ptr<std::vector<Rule>> excludedRules;
public:
	KnowledgeBase();
	KnowledgeBase(const std::shared_ptr<std::vector<Rule>> &rules);
	~KnowledgeBase();
	void addRule(Rule &rule);
	std::shared_ptr<std::vector<Rule>> getRules();
	std::shared_ptr<std::vector<Rule>> getExcludedRules();
	bool excludeRule(const Rule &rule);
	bool hasNotExcludedRules();
	bool hasExcludedRules();
	void resetExcludedRules();
};

#endif // !KNOWLEDGE_BASE

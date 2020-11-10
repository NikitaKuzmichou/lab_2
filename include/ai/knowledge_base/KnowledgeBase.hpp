#ifndef KNOWLEDGE_BASE
#define KNOWLEDGE_BASE

#include <boost/ptr_container/ptr_list.hpp>
#include "Rule.hpp"

class KnowledgeBase {
private:
	std::shared_ptr<boost::ptr_list<Rule>> rules;
	std::shared_ptr<boost::ptr_list<Rule>> excludedRules;
public:
	KnowledgeBase();
	KnowledgeBase(std::shared_ptr<boost::ptr_list<Rule>> rules);
	~KnowledgeBase();
	void addRule(Rule* rule);
	boost::ptr_list<Rule> getRules();
	boost::ptr_list<Rule> getExcludedRules();
	bool excludeRule(Rule rule);
	bool hasNotExcludedRules();
	bool hasExcludedRules();
	void resetExcludedRules();
};

#endif // !KNOWLEDGE_BASE

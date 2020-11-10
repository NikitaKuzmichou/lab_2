#ifndef KNOWLEDGE_BASE_FILLER
#define KNOWLEDGE_BASE_FILLER

#include "../../ai/knowledge_base/KnowledgeBase.hpp"

class KnowledgeBaseFiller {
private:
	std::shared_ptr<boost::ptr_list<Rule>> getCharacterTypeRules();
	std::shared_ptr<boost::ptr_list<Rule>> getCharacterNatureRules();
	std::shared_ptr<boost::ptr_list<Rule>> getOtherRules();
	std::shared_ptr<boost::ptr_list<Rule>> getCharacterClassRules();
	void appendRules(std::shared_ptr<boost::ptr_list<Rule>>, std::shared_ptr<boost::ptr_list<Rule>>);
public:
	std::shared_ptr<KnowledgeBase> getFilledKnowledgeBase();
};

#endif // !KNOWLEDGE_BASE_FILLER

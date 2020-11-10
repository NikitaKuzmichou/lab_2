#ifndef KNOWLEDGE_BASE_FILLER
#define KNOWLEDGE_BASE_FILLER

#include "../../ai/knowledge_base/KnowledgeBase.hpp"

class KnowledgeBaseFiller {
private:
	std::shared_ptr<std::list<Rule>> getCharacterTypeRules();
	std::shared_ptr<std::list<Rule>> getCharacterNatureRules();
	std::shared_ptr<std::list<Rule>> getOtherRules();
	std::shared_ptr<std::list<Rule>> getCharacterClassRules();
	void appendRules(std::shared_ptr<std::list<Rule>>, std::shared_ptr<std::list<Rule>>);
public:
	std::shared_ptr<KnowledgeBase> getFilledKnowledgeBase();
};

#endif // !KNOWLEDGE_BASE_FILLER

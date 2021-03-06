#include "../../../include/realization/knowledge_base/KnowledgeBaseFiller.hpp"

std::shared_ptr<KnowledgeBase> KnowledgeBaseFiller::getFilledKnowledgeBase() {
	auto kbRules = std::make_shared<std::vector<Rule>>();
	this->appendRules(kbRules, this->getOtherRules());
	this->appendRules(kbRules, this->getCharacterNatureRules());
	this->appendRules(kbRules, this->getCharacterTypeRules());
	this->appendRules(kbRules, this->getCharacterClassRules());
	return std::make_shared<KnowledgeBase>(kbRules);
}

std::shared_ptr<std::vector<Rule>> KnowledgeBaseFiller::getOtherRules() {
	auto rules = std::make_shared<std::vector<Rule>>();
	/**if 2.2 => 4.3*/
	auto states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(2, 2));
	rules->push_back(Rule(1, states, std::make_shared<AbstractState>(4, 3)));
	/**if 2.3 => 1.1*/
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(2, 3));
	rules->push_back(Rule(2, states, std::make_shared<AbstractState>(1, 1)));
	/**if 5.3 => 3.2*/
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 3));
	rules->push_back(Rule(3, states, std::make_shared<AbstractState>(3, 2)));
	/**if 6.2 => 2.3*/
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(6, 2));
	rules->push_back(Rule(4, states, std::make_shared<AbstractState>(2, 3)));
	/**if 4.3 => 3.3*/
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(4, 3));
	rules->push_back(Rule(5, states, std::make_shared<AbstractState>(3, 3)));
	/**if 4.3 <= 3.3*/
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(3, 3));
	rules->push_back(Rule(6, states, std::make_shared<AbstractState>(4, 3)));
	return rules;
}

std::shared_ptr<std::vector<Rule>> KnowledgeBaseFiller::getCharacterNatureRules() {
	auto rules = std::make_shared<std::vector<Rule>>();
	/**9.1 = 3.3 && 4.3 */
	auto states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(3, 3));
	states->push_back(AbstractState(4, 3));
	rules->push_back(Rule(7, states, std::make_shared<AbstractState>(9, 1)));
	/**9.2 = 3.2 && 4.4 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(3, 2));
	states->push_back(AbstractState(4, 4));
	rules->push_back(Rule(8, states, std::make_shared<AbstractState>(9, 2)));
	/**9.3 = 3.1 && 4.1 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(3, 1));
	states->push_back(AbstractState(4, 1));
	rules->push_back(Rule(9, states, std::make_shared<AbstractState>(9, 3)));
	/**9.4 = 3.2 && 4.2 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(3, 2));
	states->push_back(AbstractState(4, 2));
	rules->push_back(Rule(10, states, std::make_shared<AbstractState>(9, 4)));
	return rules;
}

std::shared_ptr<std::vector<Rule>> KnowledgeBaseFiller::getCharacterTypeRules() {
	auto rules = std::make_shared<std::vector<Rule>>();
	/**7.1 = 6.1 && 1.2 */
	auto states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(6, 1));
	states->push_back(AbstractState(1, 2));
	rules->push_back(Rule(11, states, std::make_shared<AbstractState>(7, 1)));
	/**7.2 => 6.2 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(6, 2));
	rules->push_back(Rule(12, states, std::make_shared<AbstractState>(7, 2)));
	/**7.2 <= 6.2 */
	//states = std::make_shared<std::vector<AbstractState>>();
	//states->push_back(AbstractState(7, 2));
	//rules->push_back(Rule(13, states, std::make_shared<AbstractState>(6, 2)));
	/**7.3 = 6.3 && 1.1 && 2.1 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(6, 3));
	states->push_back(AbstractState(1, 1));
	states->push_back(AbstractState(2, 1));
	rules->push_back(Rule(14, states, std::make_shared<AbstractState>(7, 3)));
	/**7.3 = 6.3 && 1.2 && 2.1 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(6, 3));
	states->push_back(AbstractState(1, 2));
	states->push_back(AbstractState(2, 1));
	rules->push_back(Rule(15, states, std::make_shared<AbstractState>(7, 3)));
	return rules;
}

std::shared_ptr<std::vector<Rule>> KnowledgeBaseFiller::getCharacterClassRules() {
	auto rules = std::make_shared<std::vector<Rule>>();
	/**8.1 = 5.2 && 7.2 && 9.2 */
	auto states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 2));
	states->push_back(AbstractState(7, 2));
	states->push_back(AbstractState(9, 2));
	rules->push_back(Rule(16, states, std::make_shared<AbstractState>(8, 1)));
	/**8.2 = 5.3 && 7.2 && 9.4 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 3));
	states->push_back(AbstractState(7, 2));
	states->push_back(AbstractState(9, 4));
	rules->push_back(Rule(17, states, std::make_shared<AbstractState>(8, 2)));
	/**8.3 = 5.2 && 7.3 && 9.3 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 2));
	states->push_back(AbstractState(7, 3));
	states->push_back(AbstractState(9, 3));
	rules->push_back(Rule(18, states, std::make_shared<AbstractState>(8, 3)));
	/**8.4 = 5.3 && 7.3 && 9.2 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 3));
	states->push_back(AbstractState(7, 3));
	states->push_back(AbstractState(9, 2));
	rules->push_back(Rule(19, states, std::make_shared<AbstractState>(8, 4)));
	/**8.5 = 5.2 && 7.3 && 9.1 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 2));
	states->push_back(AbstractState(7, 3));
	states->push_back(AbstractState(9, 1));
	rules->push_back(Rule(20, states, std::make_shared<AbstractState>(8, 5)));
	/**8.6 = 2.1 && 5.2 && 7.1 && 9.2 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(2, 1));
	states->push_back(AbstractState(5, 2));
	states->push_back(AbstractState(7, 1));
	states->push_back(AbstractState(9, 2));
	rules->push_back(Rule(21, states, std::make_shared<AbstractState>(8, 6)));
	/**8.7 = 2.2 && 5.2 && 7.1 && 9.1 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(2, 2));
	states->push_back(AbstractState(5, 2));
	states->push_back(AbstractState(7, 1));
	states->push_back(AbstractState(9, 1));
	rules->push_back(Rule(22, states, std::make_shared<AbstractState>(8, 7)));
	/**8.8 = 5.1 && 7.3 && 9.4 */
	states = std::make_shared<std::vector<AbstractState>>();
	states->push_back(AbstractState(5, 1));
	states->push_back(AbstractState(7, 3));
	states->push_back(AbstractState(9, 4));
	rules->push_back(Rule(23, states, std::make_shared<AbstractState>(8, 8)));
	return rules;
}

void KnowledgeBaseFiller::appendRules(
	                    std::shared_ptr<std::vector<Rule>> conclusionsRules,
	                            std::shared_ptr<std::vector<Rule>> rules) {
	for (auto itRule = rules->begin(); itRule != rules->end(); ++itRule) {
		conclusionsRules->push_back(*itRule);
	}
}

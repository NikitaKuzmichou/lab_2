#include "../../../include/realization/knowledge_base/ConclusionsFiller.hpp"

std::shared_ptr<Conclusions> ConclusionsFiller::getFilledConclusions() {
	auto unknowConclusions = std::make_shared<std::vector<AbstractState>>();
	unknowConclusions->push_back(AbstractState(1));
	unknowConclusions->push_back(AbstractState(2));
	unknowConclusions->push_back(AbstractState(3));
	unknowConclusions->push_back(AbstractState(4));
	unknowConclusions->push_back(AbstractState(5));
	unknowConclusions->push_back(AbstractState(6));
	unknowConclusions->push_back(AbstractState(7));
	unknowConclusions->push_back(AbstractState(8));
	unknowConclusions->push_back(AbstractState(9));
	return std::make_shared<Conclusions>(unknowConclusions);
}
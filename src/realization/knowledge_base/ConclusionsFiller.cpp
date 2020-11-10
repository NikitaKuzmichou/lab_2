#include "../../../include/realization/knowledge_base/ConclusionsFiller.hpp"

std::shared_ptr<Conclusions> ConclusionsFiller::getFilledConclusions() {
	auto unknowConclusions = std::make_shared<boost::ptr_list<AbstractState>>();
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(1).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(2).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(3).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(4).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(5).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(6).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(7).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(8).get());
	unknowConclusions.get()->push_back(std::make_shared<AbstractState>(9).get());
	return std::make_shared<Conclusions>(unknowConclusions);
}
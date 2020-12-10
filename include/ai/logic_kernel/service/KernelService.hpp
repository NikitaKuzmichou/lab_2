#ifndef KERNEL_CONCLUSIONS_SERVICE
#define KERNEL_CONCLUSIONS_SERVICE

#include "StateFinder.hpp"
#include "../Conclusions.hpp"
#include "../../knowledge_base/Rule.hpp"
#include "../../factories/interaction/AbstractInteractorFactory.hpp"
#include <vector>

class KernelService {
private:
	int maxUnknownStates;
	std::shared_ptr<StateFinder> stateFinder;
	AbstractInteractorFactory* interactionFactory;
	std::shared_ptr<std::vector<AbstractState>> confirmed;
	std::shared_ptr<std::vector<AbstractState>> notFound;
public:
	KernelService();
	KernelService(int);
	~KernelService();
	void setInteractionFactory(AbstractInteractorFactory* interactionFactory);
	void setMaxUnknownStates(int);
	bool updateConclusionsByRule(std::shared_ptr<Conclusions> conclusions, Rule& rule);
private:
	bool confirmStates(std::vector<AbstractState>& knownStates, Rule& rule);
	bool confirmUserInputStates(std::shared_ptr<Conclusions> conclusions, Rule& rule);
	void refresh();
};

#endif // !KERNEL_CONCLUSIONS_SERVICE

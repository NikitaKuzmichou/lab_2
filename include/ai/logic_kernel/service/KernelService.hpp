#ifndef KERNEL_CONCLUSIONS_SERVICE
#define KERNEL_CONCLUSIONS_SERVICE

#include "StateFinder.hpp"
#include "../Conclusions.hpp"
#include "../../knowledge_base/Rule.hpp"
#include "../../factories/interaction/AbstractInteractorFactory.hpp"
#include <list>

class KernelService {
private:
	int maxUnknownStates;
	std::shared_ptr<StateFinder> stateFinder;
	AbstractInteractorFactory* interactionFactory;
	std::list<AbstractState> confirmed;
	std::list<AbstractState> notFound;
public:
	KernelService();
	KernelService(int);
	~KernelService();
	void setInteractionFactory(AbstractInteractorFactory* interactionFactory);
	void setMaxUnknownStates(int);
	bool updateConclusionsByRule(std::shared_ptr<Conclusions> conclusions, Rule& rule);
private:
	bool confirmStates(std::list<AbstractState>& conclusions, Rule& rule);
	bool confirmUserInputStates(std::shared_ptr<Conclusions> conclusions, Rule& rule);
	void refresh();
};

#endif // !KERNEL_CONCLUSIONS_SERVICE

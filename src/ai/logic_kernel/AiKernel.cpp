#include "../../../include/ai/logic_kernel/AiKernel.hpp"

AiKernel::AiKernel(int maxUnknownStates) {
	this->maxUnknownStates = maxUnknownStates;
	this->kernelService = std::make_shared<KernelService>(maxUnknownStates);
}

AiKernel::~AiKernel() {
	this->factoriesFactory.reset();
	this->kernelService.reset();
	this->knowledgeBase.reset();
	this->conclusions.reset();
}

void AiKernel::setMaxUnknownStates(int maxUnkStates) {
	this->maxUnknownStates = maxUnkStates;
}

int AiKernel::getMaxUnknownStates() {
	return this->maxUnknownStates;
}

void AiKernel::setFactoriesFactory(std::shared_ptr<FactoriesFactory> ff) {
	this->factoriesFactory = ff;
	this->kernelService->setInteractionFactory(ff->getInteractorFactoryInstance());
}

KnowledgeBase AiKernel::getKnowledgeBase() {
	return *(this->knowledgeBase);
}

void AiKernel::setKnowledgeBase(std::shared_ptr<KnowledgeBase> kb) {
	this->knowledgeBase = kb;
}

std::shared_ptr<Conclusions> AiKernel::getConclusions() {
	return this->conclusions;
}

void AiKernel::setConclusions(std::shared_ptr<Conclusions> conclusions) {
	this->conclusions = conclusions;
}

bool AiKernel::startService() {
	int iterationNumber = 1;
	auto messanger = this->factoriesFactory->
		                            getInteractorFactoryInstance()->
		                                        getMessageInteractor();
	while (this->conclusions->hasUnknownState() &&
		   this->knowledgeBase->hasNotExcludedRules()) {
		bool ruleNotExcluded = false;
		messanger->printIterationNumber(iterationNumber);
		messanger->printInfo(this->conclusions);
		for (int i = 0; i < this->knowledgeBase->getRules()->size(); ++i) {
			bool excludeRule = this->kernelService->
				                             updateConclusionsByRule(this->conclusions,
					                                  this->knowledgeBase->getRules()->at(i));
			if (excludeRule) {
				this->getKnowledgeBase().excludeRule(
					                     this->knowledgeBase->getRules()->at(i));
				ruleNotExcluded = false;
			} else {
				++i;
			}
		}
		if (ruleNotExcluded) {
			messanger->printRuleNotExcluded();
			return false;
		}
		++iterationNumber;
	}
	if (this->conclusions->hasUnknownState()) {
		messanger->printSomeStatesNotDefined();
		return false;
	}
	return true;
}

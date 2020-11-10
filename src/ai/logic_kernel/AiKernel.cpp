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
	this->kernelService.get()->setInteractionFactory(ff.get()->getInteractorFactoryInstance());
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

void AiKernel::setConclusions(std::shared_ptr<Conclusions>) {
	this->conclusions = this->conclusions;
}

bool AiKernel::startService() {
	int iterationNumber = 1;
	auto messanger = this->factoriesFactory.get()->
		                            getInteractorFactoryInstance()->
		                                        getMessageInteractor().get();
	while (this->conclusions.get()->hasUnknownState() 
		   && this->knowledgeBase.get()->hasNotExcludedRules()) {
		bool ruleNotExcluded = false;
		messanger->printIterationNumber(iterationNumber);
		messanger->printInfo(this->conclusions);
		for (auto itRule = this->knowledgeBase.get()->getRules()->begin();
			 itRule != this->knowledgeBase.get()->getRules()->end();
			 ++itRule) {
			bool excludeRule = this->kernelService.get()->
				                 updateConclusionsByRule(this->conclusions, *itRule);
			if (excludeRule) {
				this->getKnowledgeBase().excludeRule(*itRule);
				ruleNotExcluded = false;
			}
			this->getConclusions().get()->updateKnownStates();
			if (ruleNotExcluded) {
				messanger->printRuleNotExcluded();
				return false;
			}
		}
	}
	messanger->printInfo(this->conclusions);
	return true;
}

#include "../../../../include/ai/logic_kernel/service/KernelService.hpp"
#include "../../../../include/ai/interaction/AbstractRequestInteractor.hpp"
#include "../../../../include/ai/interaction/AbstractResponseInteractor.hpp"

KernelService::KernelService() {
	this->stateFinder = std::make_shared<StateFinder>();
	this->confirmed = std::list<AbstractState>();
	this->maxUnknownStates = 1;
}

KernelService::KernelService(int maxUnknownStates) {
	this->maxUnknownStates = maxUnknownStates;
}

KernelService::~KernelService() {
	this->stateFinder.reset();
	this->confirmed.clear();
	this->notFound.clear();
	delete this->interactionFactory;
}

void KernelService::setInteractionFactory(AbstractInteractorFactory *interactionFactory) {
	this->interactionFactory = interactionFactory;
}

void KernelService::setMaxUnknownStates(int maxUnknownStates) {
	this->maxUnknownStates = maxUnknownStates;
}

bool KernelService::updateConclusionsByRule(std::shared_ptr<Conclusions> conclusions, Rule &rule) {
	this->refresh();
	bool excludeRule = false;
	if (!this->confirmStates(*(conclusions.get()->getKnown()), rule)) {
		excludeRule = true;
	} else if (rule.getStates().get()->size() - this->confirmed.size() > this->maxUnknownStates) {
		excludeRule = false;
	} else if (this->confirmUserInputStates(conclusions, rule)) {
		conclusions.get()->addFreshState(*(rule.getConsequence()));
		excludeRule = true;
	} else {
		excludeRule = true;
	}
	return excludeRule;
}

bool KernelService::confirmStates(std::list<AbstractState> &knownStates, Rule &rule) {
	bool noDivergence = true;
	for (auto itKnownState = knownStates.begin();
		 itKnownState != knownStates.end(); ++itKnownState) {
		this->stateFinder.get()->findState(*itKnownState, rule);
		StateStatus status = this->stateFinder.get()->getStatus();
		if (status == StateStatus::CONFIRMED) {
			this->confirmed.push_back(this->stateFinder.get()->getState());
		} else if (status == StateStatus::NOT_FOUND) {
			this->notFound.push_back(this->stateFinder.get()->getState());
		} else if (status == StateStatus::DIVERGENCE) {
			noDivergence = false;
			break;
		}
	}
	return noDivergence;
}

bool KernelService::confirmUserInputStates(
	                                  std::shared_ptr<Conclusions> conclusions, Rule &rule) {
	auto reqInteractor = this->interactionFactory->getRequestInteractor();;
	auto respInteractor = this->interactionFactory->getResponseInteractor();;
	bool allInputsConfirmed = true;
	for (auto itUnk = this->notFound.begin(); itUnk != this->notFound.end(); ++itUnk) {
		reqInteractor.get()->printRequest((*itUnk).getId());
		auto usrInput = respInteractor.get()->readState((*itUnk).getId());
		conclusions.get()->addUserInput(*usrInput);
		this->stateFinder.get()->findState(*usrInput, rule);
		if (this->stateFinder.get()->getStatus() == StateStatus::DIVERGENCE) {
			allInputsConfirmed = false;
			break;
		}
	}
	return allInputsConfirmed;
}

void KernelService::refresh() {
	this->confirmed.clear();
	this->notFound.clear();
}

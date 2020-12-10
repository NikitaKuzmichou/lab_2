#include "../../../../include/ai/logic_kernel/service/KernelService.hpp"
#include "../../../../include/ai/interaction/AbstractRequestInteractor.hpp"
#include "../../../../include/ai/interaction/AbstractResponseInteractor.hpp"

KernelService::KernelService() {
	this->stateFinder = std::make_shared<StateFinder>();
	this->confirmed = std::make_shared<std::vector<AbstractState>>();
	this->notFound = std::make_shared<std::vector<AbstractState>>();
	this->maxUnknownStates = 1;
}

KernelService::KernelService(int maxUnknownStates) {
	this->maxUnknownStates = maxUnknownStates;
	this->stateFinder = std::make_shared<StateFinder>();
	this->notFound = std::make_shared<std::vector<AbstractState>>();
	this->confirmed = std::make_shared<std::vector<AbstractState>>();
}

KernelService::~KernelService() {
	this->stateFinder.reset();
	this->confirmed.reset();
	this->notFound.reset();
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
	if (this->confirmStates(*(conclusions->getKnown()), rule)) {
		excludeRule = true;
	} else if (this->notFound->size() > this->maxUnknownStates) {
		excludeRule = false;
	} else if (this->confirmUserInputStates(conclusions, rule)) {
		conclusions->addKnownState(*(rule.getConsequence()));
		excludeRule = true;
	} else {
		excludeRule = true;
	}
	return excludeRule;
}

bool KernelService::confirmStates(std::vector<AbstractState>& knownStates,
	                              Rule& rule) {
	bool hasDivergence = false;
	for (int i = 0; i < rule.getStates()->size(); ++i) {
		this->stateFinder->findState(knownStates, rule.getStates()->at(i));
		StateStatus status = this->stateFinder->getStatus();
		if (status == StateStatus::CONFIRMED) {
			this->confirmed->push_back(rule.getStates()->at(i));
		}
		else if (status == StateStatus::NOT_FOUND) {
			this->notFound->push_back(rule.getStates()->at(i));
		}
		else if (status == StateStatus::DIVERGENCE) {
			hasDivergence = true;
			break;
		}
	}
	return hasDivergence;
}

bool KernelService::confirmUserInputStates(
	                                    std::shared_ptr<Conclusions> conclusions,
	                                                                 Rule &rule) {
	auto reqInteractor = this->interactionFactory->getRequestInteractor();
	auto respInteractor = this->interactionFactory->getResponseInteractor();
	bool allInputsConfirmed = true;
	for (int i = 0; i < notFound->size(); ++i) {
		reqInteractor->printRequest(notFound->at(i).getId());
		auto usrInput = respInteractor->readState(notFound->at(i).getId());
		conclusions->addKnownState(*usrInput);
		if (this->stateFinder->findState(*(rule.getStates()), *usrInput) !=
			StateStatus::CONFIRMED) {
			allInputsConfirmed = false;
			break;
		}
	}
	return allInputsConfirmed;
}

void KernelService::refresh() {
	this->confirmed->clear();
	this->notFound->clear();
}

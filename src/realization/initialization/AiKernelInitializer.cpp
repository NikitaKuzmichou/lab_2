#include "../../../include/realization/initialization/AiKernelInitializer.hpp"

AiKernelInitializer::AiKernelInitializer() {
	this->aiKernel = std::make_shared<AiKernel>(1);
}

void AiKernelInitializer::initializeKnowledgeBase() {
	KnowledgeBaseFiller kbFiller;
	this->aiKernel->setKnowledgeBase(kbFiller.getFilledKnowledgeBase());
}

void AiKernelInitializer::initializeFactoriesFactory() {
	FactoriesFactory::getInstance()->
		setInteractorFactoryInstance(CmdInteractorFactory::getInstance());
	this->aiKernel->setFactoriesFactory(FactoriesFactory::getInstance());
}

void AiKernelInitializer::initializeConclusions() {
	ConclusionsFiller conclFiller;
	CmdUserInitialData initializer(
		FactoriesFactory::getInstance()->getInteractorFactoryInstance()->getResponseInteractor(),
		FactoriesFactory::getInstance()->getInteractorFactoryInstance()->getRequestInteractor());
	auto conclusions = conclFiller.getFilledConclusions();
	this->getInitialUserInput(conclusions, initializer);
	this->aiKernel->setConclusions(conclusions);
}

AiKernel AiKernelInitializer::getInitializedAiKernel() {
	return *(this->aiKernel);
}

void AiKernelInitializer::getInitialUserInput(
	                           std::shared_ptr<Conclusions> conclusions,
	                                       CmdUserInitialData &initializer) {
	while (!initializer.inputIsOver()) {
		initializer.printMainMessageMenu();
		auto usrInput = initializer.readUserInput();
		if (usrInput != nullptr) {
			conclusions->addKnownState(*usrInput);
		}
	}
}

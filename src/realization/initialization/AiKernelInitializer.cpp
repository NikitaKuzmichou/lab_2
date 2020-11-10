#include "../../../include/realization/initialization/AiKernelInitializer.hpp"

AiKernelInitializer::AiKernelInitializer() {
	this->aiKernel = std::make_shared<AiKernel>(1);
}

void AiKernelInitializer::initializeKnowledgeBase() {
	KnowledgeBaseFiller kbFiller;
	this->aiKernel.get()->setKnowledgeBase(kbFiller.getFilledKnowledgeBase());
}

void AiKernelInitializer::initializeFactoriesFactory() {
	FactoriesFactory::getInstance()->
		setInteractorFactoryInstance(CmdInteractorFactory::getInstance());
	this->aiKernel.get()->setFactoriesFactory(FactoriesFactory::getInstance());
}

void AiKernelInitializer::initializeConclusions() {
	ConclusionsFiller conclFiller;
	CmdUserInitialData initializer(
		FactoriesFactory::getInstance().get()->getInteractorFactoryInstance()->getResponseInteractor(),
		FactoriesFactory::getInstance().get()->getInteractorFactoryInstance()->getRequestInteractor());
	auto conclusions = conclFiller.getFilledConclusions();
	this->getInitialUserInput(conclusions, initializer);
	this->aiKernel.get()->setConclusions(conclusions);
}

AiKernel AiKernelInitializer::getInitializedAiKernel() {
	return *(this->aiKernel);
}

void AiKernelInitializer::getInitialUserInput(
	                           std::shared_ptr<Conclusions> conclusions,
	                                       CmdUserInitialData initializer) {
	while (!initializer.inputIsOver()) {
		initializer.printMainMessageMenu();
		auto usrInput = initializer.readUserInput();
		if (usrInput != nullptr) {
			conclusions.get()->addUserInput(usrInput.get());
		}
	}
}

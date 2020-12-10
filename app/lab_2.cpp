#include <Windows.h>
#include "../include/realization/initialization/AiKernelInitializer.hpp"


int main() {
	SetConsoleOutputCP(1251);
	AiKernelInitializer initializer;
	initializer.initializeFactoriesFactory();
	initializer.initializeKnowledgeBase();
	initializer.initializeConclusions();
	AiKernel aiKernel = initializer.getInitializedAiKernel();
	if (aiKernel.startService()) {
		std::cout << "**Выполнение вычислений завершено успешно**"
			<< std::endl
			<< "**Результат вычислений**"
			<< std::endl;
	}
	else {
		std::cout << "**Выполнение вычислений не завершено до конца**"
			<< std::endl
			<< "**Вычисленная информация на момент завершения вычислений**"
			<< std::endl;
	}
	FactoriesFactory::getInstance()->getInteractorFactoryInstance()
		->getMessageInteractor()->printInfo(aiKernel.getConclusions());
	return 0;
}

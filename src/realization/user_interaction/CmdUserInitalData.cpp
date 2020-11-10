#include "../../../include/realization/user_interaction/CmdUserInitialData.hpp"
#include <iostream>

CmdUserInitialData::CmdUserInitialData(std::shared_ptr<AbstractResponseInteractor> respInter,
	                                   std::shared_ptr<AbstractRequestInteractor> reqInter) {
	this->responseInteractor = respInter;
	this->requestInteractor = reqInter;
}

void CmdUserInitialData::printMainMessageMenu() {
	std::cout << "Введите начальную информацию: \n"
		      << "1) Предпочитаемый стиль боя\n"
		      << "2) Предпочитаемая магия\n"
		      << "3) Ради чего ты сражаешься?\n"
		      << "4) Тип мировоззрения?\n"
		      << "5) На сколько персонаж социален?\n"
		      << "6) Закончить ввод информации"
		      << std::endl;
}

std::shared_ptr<AbstractState> CmdUserInitialData::readUserInput() {
	int inputVal;
	std::cin >> inputVal;
	return this->makeDecision(inputVal);
}

bool CmdUserInitialData::inputIsOver() {
	return this->inputOver;
}


std::shared_ptr<AbstractState> CmdUserInitialData::makeDecision(int input) {
	if (input > 0 && input < 6) {
		this->requestInteractor.get()->printRequest(input);
		auto readedState = this->responseInteractor.get()->readState(input);
		return readedState;
	} else if (input == 6) {
		this->inputOver = true;
	}
	return nullptr;
}
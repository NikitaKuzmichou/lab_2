#include "../../../include/realization/user_interaction/CmdUserInitialData.hpp"
#include <iostream>

CmdUserInitialData::CmdUserInitialData(std::shared_ptr<AbstractResponseInteractor> respInter,
	                                   std::shared_ptr<AbstractRequestInteractor> reqInter) {
	this->responseInteractor = respInter;
	this->requestInteractor = reqInter;
	this->selectedInputs = std::make_shared<std::vector<int>>();
}

void CmdUserInitialData::printMainMessageMenu() {
	std::cout << "������� ��������� ����������: \n"
		      << "1) �������������� ����� ���\n"
		      << "2) �������������� �����\n"
		      << "3) ���� ���� �� ����������?\n"
		      << "4) ��� �������������?\n"
		      << "5) �� ������� �������� ��������?\n"
		      << "6) ��������� ���� ����������"
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
		this->requestInteractor->printRequest(input);
		auto readedState = this->responseInteractor->readState(input);
		readedState->setInitType(InitType::FROM_START);
		return readedState;
	} else if (input == 6) {
		this->inputOver = true;
	}
	return nullptr;
}
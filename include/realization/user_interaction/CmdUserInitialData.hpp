#ifndef CMD_USER_INITIAL_DATA
#define CMD_USER_INITIAL_DATA

#include "../../ai/states/AbstractState.hpp"
#include "CmdResponseInteractor.hpp"
#include "CmdRequestInteractor.hpp"
#include <vector>

class CmdUserInitialData {
private:
	std::shared_ptr<AbstractResponseInteractor> responseInteractor;
	std::shared_ptr<AbstractRequestInteractor> requestInteractor;
	std::shared_ptr<std::vector<int>> selectedInputs;
	bool inputOver = false;
public:
	CmdUserInitialData(std::shared_ptr<AbstractResponseInteractor> respInter,
		               std::shared_ptr<AbstractRequestInteractor> reqInter);
	void printMainMessageMenu();
	std::shared_ptr<AbstractState> readUserInput();
	bool inputIsOver();
private:
	std::shared_ptr<AbstractState> makeDecision(int input);
};

#endif // !CMD_USER_INITIAL_DATA

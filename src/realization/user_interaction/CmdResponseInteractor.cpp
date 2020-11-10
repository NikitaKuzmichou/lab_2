#include "../../../include/realization/user_interaction/CmdResponseInteractor.hpp"

CmdResponseInteractor::CmdResponseInteractor() : AbstractResponseInteractor(){

}

std::shared_ptr<AbstractState> CmdResponseInteractor::readState(unsigned int id) {
	std::cin >> this;
	this->stateId = id;
	return this->getReadedState();
}

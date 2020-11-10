#include "../../../include/realization/user_interaction/CmdRequestInteractor.hpp"

CmdRequestInteractor::CmdRequestInteractor(
	                 std::shared_ptr<AbstractRequestsStorage> reqStorage)
	                                   : AbstractRequestInteractor(reqStorage) {

}

void CmdRequestInteractor::printRequest(unsigned int id) {
	std::cout << this->reqStorage.get()->getRequest(id) << std::endl;
}

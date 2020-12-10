#include "../../../include/realization/factories/CmdInteractorFactory.hpp"
#include "../../../include/realization/user_interaction/CmdResponseInteractor.hpp"
#include "../../../include/realization/user_interaction/CmdRequestInteractor.hpp"
#include "../../../include/realization/user_interaction/CmdMessageInteractor.hpp"
#include "../../../include/realization/user_interaction/msg_storage/CmdMessageStorage.hpp"
#include "../../../include/realization/user_interaction/msg_storage/CmdRequestsStorage.hpp"

CmdInteractorFactory::CmdInteractorFactory() : AbstractInteractorFactory() {

}

AbstractInteractorFactory* CmdInteractorFactory::getInstance() {
	if (!instance) {
		instance = new CmdInteractorFactory();
	}
	return instance;
}

std::shared_ptr<AbstractRequestInteractor> CmdInteractorFactory::getRequestInteractor() {
	auto msgStorage = std::make_shared<CmdRequestsStorage>();
	return std::make_shared<CmdRequestInteractor>(msgStorage);
}

std::shared_ptr<AbstractResponseInteractor> CmdInteractorFactory::getResponseInteractor() {
	return std::make_shared<CmdResponseInteractor>();
}

std::shared_ptr<AbstractMessageInteractor> CmdInteractorFactory::getMessageInteractor() {
	auto msgStorage = std::make_shared<CmdMessageStorage>();
	return std::make_shared<CmdMessageInteractor>(msgStorage);
}

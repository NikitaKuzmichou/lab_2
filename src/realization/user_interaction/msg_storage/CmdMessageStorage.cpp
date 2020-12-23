#include "../../../../include/realization/user_interaction/msg_storage/CmdMessageStorage.hpp"
#include <sstream>

std::string CmdMessageStorage::getStateMsg(AbstractState state) {
	std::ostringstream oss;
	switch (state.getId()) {
	case 1:
		oss << "Персонаж предпочитает сражаться ";
		oss << this->resolveFightingMethod(state.getValue());
		break;
	case 2:
		oss << "Персонаж предпочитает ";
		oss << this->resolvePreferredMagic(state.getValue());
		break;
	case 3:
		oss << "Персонаж сражается ";
		oss << this->resolveFightingReason(state.getValue());
		break;
	case 4:
		oss << "У персонажа ";
		oss << this->resolveAligment(state.getValue());
		oss << " мировоззрение.";
		break;
	case 5:
		oss << "Персонаж ";
		oss << this->resolveSocialization(state.getValue());
		break;
	case 6:
		oss << "Персонаж больше доверяет ";
		oss << this->resolveMagicOrWeapon(state.getValue());
		break;
	case 7:
		oss << "Тип персонажа: ";
		oss << this->resolveCharacterType(state.getValue());
		break;
	case 8:
		oss << "Класс персонажа: ";
		oss << this->resolveCharacterClass(state.getValue());
		break;
	case 9:
		oss << "У персонажа ";
		oss << this->resolveCharacterNature(state.getValue());
		oss << " тип характера.";
		break;
	default:
		oss << "*произошла ошибка*";
	}
	oss << std::endl;
	oss << "===>Информация получена ";
	oss << this->resolveInitializingType(state.getInitType());
	return oss.str();
}

std::string CmdMessageStorage::getIterNumMsg(int number) {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== Текущая итерация: "
		<< number 
		<< " ===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::getRuleNotExcluded() {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== Выполнение программы было остановлено по причине "
		<< "ни одно правило не было исключено "
		<< "===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::getKnownStatesMsg() {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== Информация об определённых параметрах "
		<< "===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::getUnknownStatesMsg() {
	std::ostringstream oss;
	oss << "========================================\n"
		<< "=== Информация о неопределённых параметрах "
		<< "===\n"
		<< "========================================";
	return oss.str();
}

std::string CmdMessageStorage::getSomeStatesNotDefined() {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== Все правила были исключены, "
		<< "но некоторые значения остались не определены "
		<< "===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::resolveFightingMethod(int value) {
	switch (value) {
	case 1:
		return "в ближнем бою.";
	case 2:
		return "в дальнем бою.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolvePreferredMagic(int value) {
	switch (value) {
	case 1:
		return "стихийную магию.";
	case 2:
		return "призывать слуг, сражающихся за него.";
	case 3:
		return "не использовать магию вообще.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveFightingReason(int value) {
	switch (value) {
	case 1:
		return "ради мира и справедливости.";
	case 2:
		return "потому приходится сражаться.";
	case 3:
		return "только ради себя.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveAligment(int value) {
	switch (value) {
	case 1:
		return "доброе";
	case 2:
		return "хаотичное";
	case 3:
		return "злое";
	case 4:
		return "не определённое";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveSocialization(int value) {
	switch (value) {
	case 1:
		return "крайне социален.";
	case 2:
		return "умеренно социален.";
	case 3:
		return "асоциален.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveMagicOrWeapon(int value) {
	switch (value) {
	case 1:
		return "магии.";
	case 2:
		return "оружию.";
	case 3:
		return "магии и оружию.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveCharacterType(int value) {
	switch (value) {
	case 1:
		return "маг.";
	case 2:
		return "боец.";
	case 3:
		return "смешанный.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveCharacterClass(int value) {
	switch (value) {
	case 1:
		return "воин.";
	case 2:
		return "варвар.";
	case 3:
		return "паладин.";
	case 4:
		return "рейнджер.";
	case 5:
		return "разбойник.";
	case 6:
		return "волшебник.";
	case 7:
		return "чернокнижник.";
	case 8:
		return "бард.";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveCharacterNature(int value) {
	switch (value) {
	case 1:
		return "эгоистичный";
	case 2:
		return "не определённый";
	case 3:
		return "альтруистичный";
	case 4:
		return "хаотичный";
	default:
		return "*не определено*";
	}
}

std::string CmdMessageStorage::resolveInitializingType(InitType initType) {
	switch (initType) {
	case InitType::FROM_START:
		return "в момент начала выполнения";
	case InitType::FROM_CONCLUSIONS:
		return "на основании известных правил";
	case InitType::FROM_USER:
		return "на основании пользовательского ввода";
	default:
		return "*не определено*";
	}
}

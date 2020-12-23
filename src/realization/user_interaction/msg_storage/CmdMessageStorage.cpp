#include "../../../../include/realization/user_interaction/msg_storage/CmdMessageStorage.hpp"
#include <sstream>

std::string CmdMessageStorage::getStateMsg(AbstractState state) {
	std::ostringstream oss;
	switch (state.getId()) {
	case 1:
		oss << "�������� ������������ ��������� ";
		oss << this->resolveFightingMethod(state.getValue());
		break;
	case 2:
		oss << "�������� ������������ ";
		oss << this->resolvePreferredMagic(state.getValue());
		break;
	case 3:
		oss << "�������� ��������� ";
		oss << this->resolveFightingReason(state.getValue());
		break;
	case 4:
		oss << "� ��������� ";
		oss << this->resolveAligment(state.getValue());
		oss << " �������������.";
		break;
	case 5:
		oss << "�������� ";
		oss << this->resolveSocialization(state.getValue());
		break;
	case 6:
		oss << "�������� ������ �������� ";
		oss << this->resolveMagicOrWeapon(state.getValue());
		break;
	case 7:
		oss << "��� ���������: ";
		oss << this->resolveCharacterType(state.getValue());
		break;
	case 8:
		oss << "����� ���������: ";
		oss << this->resolveCharacterClass(state.getValue());
		break;
	case 9:
		oss << "� ��������� ";
		oss << this->resolveCharacterNature(state.getValue());
		oss << " ��� ���������.";
		break;
	default:
		oss << "*��������� ������*";
	}
	oss << std::endl;
	oss << "===>���������� �������� ";
	oss << this->resolveInitializingType(state.getInitType());
	return oss.str();
}

std::string CmdMessageStorage::getIterNumMsg(int number) {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== ������� ��������: "
		<< number 
		<< " ===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::getRuleNotExcluded() {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== ���������� ��������� ���� ����������� �� ������� "
		<< "�� ���� ������� �� ���� ��������� "
		<< "===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::getKnownStatesMsg() {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== ���������� �� ����������� ���������� "
		<< "===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::getUnknownStatesMsg() {
	std::ostringstream oss;
	oss << "========================================\n"
		<< "=== ���������� � ������������� ���������� "
		<< "===\n"
		<< "========================================";
	return oss.str();
}

std::string CmdMessageStorage::getSomeStatesNotDefined() {
	std::ostringstream oss;
	oss << "====================================\n"
		<< "=== ��� ������� ���� ���������, "
		<< "�� ��������� �������� �������� �� ���������� "
		<< "===\n"
		<< "====================================";
	return oss.str();
}

std::string CmdMessageStorage::resolveFightingMethod(int value) {
	switch (value) {
	case 1:
		return "� ������� ���.";
	case 2:
		return "� ������� ���.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolvePreferredMagic(int value) {
	switch (value) {
	case 1:
		return "��������� �����.";
	case 2:
		return "��������� ����, ����������� �� ����.";
	case 3:
		return "�� ������������ ����� ������.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveFightingReason(int value) {
	switch (value) {
	case 1:
		return "���� ���� � ��������������.";
	case 2:
		return "������ ���������� ���������.";
	case 3:
		return "������ ���� ����.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveAligment(int value) {
	switch (value) {
	case 1:
		return "������";
	case 2:
		return "���������";
	case 3:
		return "����";
	case 4:
		return "�� �����������";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveSocialization(int value) {
	switch (value) {
	case 1:
		return "������ ��������.";
	case 2:
		return "�������� ��������.";
	case 3:
		return "���������.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveMagicOrWeapon(int value) {
	switch (value) {
	case 1:
		return "�����.";
	case 2:
		return "������.";
	case 3:
		return "����� � ������.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveCharacterType(int value) {
	switch (value) {
	case 1:
		return "���.";
	case 2:
		return "����.";
	case 3:
		return "���������.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveCharacterClass(int value) {
	switch (value) {
	case 1:
		return "����.";
	case 2:
		return "������.";
	case 3:
		return "�������.";
	case 4:
		return "��������.";
	case 5:
		return "���������.";
	case 6:
		return "���������.";
	case 7:
		return "������������.";
	case 8:
		return "����.";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveCharacterNature(int value) {
	switch (value) {
	case 1:
		return "�����������";
	case 2:
		return "�� �����������";
	case 3:
		return "��������������";
	case 4:
		return "���������";
	default:
		return "*�� ����������*";
	}
}

std::string CmdMessageStorage::resolveInitializingType(InitType initType) {
	switch (initType) {
	case InitType::FROM_START:
		return "� ������ ������ ����������";
	case InitType::FROM_CONCLUSIONS:
		return "�� ��������� ��������� ������";
	case InitType::FROM_USER:
		return "�� ��������� ����������������� �����";
	default:
		return "*�� ����������*";
	}
}

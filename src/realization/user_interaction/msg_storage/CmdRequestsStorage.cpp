#include "../../../../include/realization/user_interaction/msg_storage/CmdRequestsStorage.hpp"
#include <sstream>

std::string CmdRequestsStorage::getRequest(unsigned int id) {
	std::ostringstream oss;
	switch (id) {
	case 1:
		oss << "�������������� ����� ���:\n"
			<< "1) ������� ���;\n"
			<< "2) ������� ���.";
		break;
	case 2:
		oss << "�������������� �����:\n"
			<< "1) ���������;\n"
			<< "2) ������ ����, ����������� �� ����;\n"
			<< "3) ��� ����� �����?..";
		break;
	case 3:
		oss << "���� ���� �� ����������?\n"
			<< "1) ���� ���� � ��������������;\n"
			<< "2) �� ����� ��������;\n"
			<< "3) ������ ���� ����.";
		break;
	case 4:
		oss << "�������������:\n"
			<< "1) ������;\n"
			<< "2) ���������;\n"
			<< "3) ����;\n"
			<< "4) �����.";
		break;
	case 5:
		oss << "�� ������� �������� ��������?\n"
			<< "1) ������ ��������;\n"
			<< "2) ��������;\n"
			<< "3) ���������.\n";
		break;
	case 6:
		oss << "���� ��������� ������ ����� ��� ������:\n"
			<< "1) �����;\n"
			<< "2) ������;\n"
			<< "3) � ���� � ����.";
		break;
	case 7:
		oss << "��� ���������:\n"
			<< "1) ���;\n"
			<< "2) ����;\n"
			<< "3) ���������.";
		break;
	case 8:
		oss << "�����:\n"
			<< "1) ����;\n"
			<< "2) ������;\n"
			<< "3) �������;\n"
			<< "4) ��������;\n"
			<< "5) ���������;\n"
			<< "6) ���������;\n"
			<< "7) ������������;\n"
			<< "8) ����.";
		break;
	case 9:
		oss << "��� ��������� ���������:\n"
			<< "1) �����������;\n"
			<< "2) �� ��������;\n"
			<< "3) ��������������;\n"
			<< "4) ���������.";
		break;
	default:
		oss << "Error in CmdInteractorFactory->getRequestInteractor(" << id << ")";
	}
	return oss.str();
}

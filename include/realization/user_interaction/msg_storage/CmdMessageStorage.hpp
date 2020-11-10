#ifndef CMD_MESSAGE_STORAGE
#define CMD_MESSAGE_STORAGE

#include "../../../ai/interaction/msg_storage/AbstractMessageStorage.hpp"

class CmdMessageStorage : public AbstractMessageStorage {
private:
	std::string resolveFightingMethod(int value);
	std::string resolvePreferredMagic(int value);
	std::string resolveFightingReason(int valud);
	std::string resolveAligment(int valud);
	std::string resolveSocialization(int valud);
	std::string resolveMagicOrWeapon(int valud);
	std::string resolveCharacterType(int valud);
	std::string resolveCharacterClass(int valud);
	std::string resolveCharacterNature(int valud);
public:
	virtual std::string getStateMsg(AbstractState state) override;
	virtual std::string getIterNumMsg(int number) override;
	virtual std::string getRuleNotExcluded() override;
	virtual std::string getKnownStatesMsg() override;
	virtual std::string getUnknownStatesMsg() override;
};

#endif // !CMD_MESSAGE_STORAGE

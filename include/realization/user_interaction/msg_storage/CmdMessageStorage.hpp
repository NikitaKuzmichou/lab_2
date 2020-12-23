#ifndef CMD_MESSAGE_STORAGE
#define CMD_MESSAGE_STORAGE

#include "../../../ai/interaction/msg_storage/AbstractMessageStorage.hpp"

class CmdMessageStorage : public AbstractMessageStorage {
private:
	std::string resolveFightingMethod(int value);
	std::string resolvePreferredMagic(int value);
	std::string resolveFightingReason(int value);
	std::string resolveAligment(int value);
	std::string resolveSocialization(int value);
	std::string resolveMagicOrWeapon(int value);
	std::string resolveCharacterType(int value);
	std::string resolveCharacterClass(int value);
	std::string resolveCharacterNature(int value);
	std::string resolveInitializingType(InitType initType);
public:
	virtual std::string getStateMsg(AbstractState state) override;
	virtual std::string getIterNumMsg(int number) override;
	virtual std::string getRuleNotExcluded() override;
	virtual std::string getKnownStatesMsg() override;
	virtual std::string getUnknownStatesMsg() override;
	virtual std::string getSomeStatesNotDefined() override;
};

#endif // !CMD_MESSAGE_STORAGE

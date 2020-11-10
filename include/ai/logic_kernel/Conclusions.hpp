#ifndef CONCLUSION
#define CONCLUSION

#include <list>
#include "../states/AbstractState.hpp"

class Conclusions {
private:
	std::shared_ptr<std::list<AbstractState>> known;
	std::shared_ptr<std::list<AbstractState>> unknown;
	std::shared_ptr<std::list<AbstractState>> fresh;
public:
	Conclusions();
	Conclusions(std::shared_ptr<std::list<AbstractState>> unknown);
	~Conclusions();
	void addUserInput(const AbstractState& state);
	std::shared_ptr<std::list<AbstractState>> getKnown();
	bool addUnknownState(const AbstractState& state);
	std::shared_ptr<std::list<AbstractState>> getUnknown();
	void addFreshState(const AbstractState& state);
	std::shared_ptr<std::list<AbstractState>> getFresh();
	void updateKnownStates();
	bool hasUnknownState();
private:
	bool isAlreadyStored(const AbstractState& state);
	void removeFromUnknownStates(const AbstractState& state);
};

#endif //!CONCLUSION
#ifndef CONCLUSION
#define CONCLUSION

#include <vector>
#include "../states/AbstractState.hpp"

class Conclusions {
private:
	std::shared_ptr<std::vector<AbstractState>> known;
	std::shared_ptr<std::vector<AbstractState>> unknown;
public:
	Conclusions();
	Conclusions(std::shared_ptr<std::vector<AbstractState>> unknown);
	~Conclusions();
	void addKnownState(const AbstractState& state);
	std::shared_ptr<std::vector<AbstractState>> getKnown();
	bool addUnknownState(const AbstractState& state);
	std::shared_ptr<std::vector<AbstractState>> getUnknown();
	bool hasUnknownState();
private:
	bool isAlreadyStored(const AbstractState& state);
	void removeFromUnknownStates(const AbstractState& state);
};

#endif //!CONCLUSION
#ifndef CONCLUSION
#define CONCLUSION

#include <boost/ptr_container/ptr_list.hpp>
#include "../states/AbstractState.hpp"

class Conclusions {
private:
	std::shared_ptr<boost::ptr_list<AbstractState>> known;
	std::shared_ptr<boost::ptr_list<AbstractState>> unknown;
	std::shared_ptr<boost::ptr_list<AbstractState>> fresh;
public:
	Conclusions();
	Conclusions(std::shared_ptr<boost::ptr_list<AbstractState>> unknown);
	~Conclusions();
	void addUserInput(AbstractState* state);
	std::shared_ptr<boost::ptr_list<AbstractState>> getKnown();
	bool addUnknownState(AbstractState* state);
	std::shared_ptr<boost::ptr_list<AbstractState>> getUnknown();
	void addFreshState(AbstractState* state);
	std::shared_ptr<boost::ptr_list<AbstractState>> getFresh();
	void updateKnownStates();
	bool hasUnknownState();
private:
	bool isAlreadyStored(AbstractState* state);
	void removeFromUnknownStates(AbstractState* state);
};

#endif //!CONCLUSION
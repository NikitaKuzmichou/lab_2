#ifndef STATE_FINDER
#define STATE_FINDER

#include "StateStatus.hpp"
#include "../../knowledge_base/Rule.hpp"
#include "../../states/AbstractState.hpp"

class StateFinder {
private:
	StateStatus status;
	AbstractState state;
public:
	StateFinder();
	StateStatus getStatus();
	AbstractState getState();
	StateStatus findState(AbstractState& state, Rule& rule);
};

#endif // !STATE_FINDER

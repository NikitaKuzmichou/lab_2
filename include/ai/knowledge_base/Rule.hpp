#ifndef ABSTRACT_RULE
#define ABSTRACT_RULE

#include "../states/AbstractState.hpp"
#include <list>

class Rule {
private:
	unsigned int id;
	std::shared_ptr<std::list<AbstractState>> states;
	std::shared_ptr<AbstractState> consequence;
public:
	Rule();
	Rule(int id);
	Rule(int id, const std::shared_ptr<std::list<AbstractState>>,
		         const std::shared_ptr<AbstractState>);
	~Rule();
	void setId(unsigned int id);
	unsigned int getId();
	void set—onsequence(std::shared_ptr<AbstractState> consequence);
	std::shared_ptr<AbstractState> getConsequence();
	void addState(AbstractState &state);
	void setStates(std::shared_ptr<std::list<AbstractState>> states);
	std::shared_ptr<std::list<AbstractState>> getStates();
	friend bool operator== (const Rule& rule1, const Rule& rule2);
	friend bool operator!= (const Rule& rule1, const Rule& rule2);
};

#endif // !ABSTRACT_RULE

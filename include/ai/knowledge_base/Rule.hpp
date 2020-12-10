#ifndef ABSTRACT_RULE
#define ABSTRACT_RULE

#include "../states/AbstractState.hpp"
#include <vector>

class Rule {
private:
	unsigned int id;
	std::shared_ptr<std::vector<AbstractState>> states;
	std::shared_ptr<AbstractState> consequence;
public:
	Rule();
	Rule(int id);
	Rule(int id, const std::shared_ptr<std::vector<AbstractState>>,
		         const std::shared_ptr<AbstractState>);
	~Rule();
	void setId(unsigned int id);
	unsigned int getId();
	void set—onsequence(std::shared_ptr<AbstractState> consequence);
	std::shared_ptr<AbstractState> getConsequence();
	void addState(AbstractState &state);
	void setStates(std::shared_ptr<std::vector<AbstractState>> states);
	std::shared_ptr<std::vector<AbstractState>> getStates();
	friend bool operator== (const Rule& rule1, const Rule& rule2);
	friend bool operator!= (const Rule& rule1, const Rule& rule2);
	friend std::ostream& operator<< (std::ostream& os, const Rule& rule);
};

#endif // !ABSTRACT_RULE

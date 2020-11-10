#ifndef ABSTRACT_RULE
#define ABSTRACT_RULE

#include <boost/ptr_container/ptr_list.hpp>
#include "../states/AbstractState.hpp"

class Rule {
private:
	unsigned int id;
	std::shared_ptr<boost::ptr_list<AbstractState>> states;
	std::shared_ptr<AbstractState> consequence;
public:
	Rule();
	Rule(int id);
	Rule(int id, std::shared_ptr<boost::ptr_list<AbstractState>>,
		 std::shared_ptr<AbstractState>);
	~Rule();
	void setId(unsigned int id);
	unsigned int getId();
	void set—onsequence(std::shared_ptr<AbstractState> consequence);
	std::shared_ptr<AbstractState> get—onsequence();
	void addState(AbstractState* state);
	void setStates(std::shared_ptr<boost::ptr_list<AbstractState>> states);
	std::shared_ptr<boost::ptr_list<AbstractState>> getStates();
	friend bool operator== (const Rule& rule1, const Rule& rule2);
	friend bool operator!= (const Rule& rule1, const Rule& rule2);
};

#endif // !ABSTRACT_RULE

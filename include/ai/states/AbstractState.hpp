#ifndef ABSTRACT_VALUE
#define ABSTRACT_VALUE

#include <iostream>
#include "InitType.hpp"

class AbstractState {
private:
	unsigned int id;
	int value;
	bool initialized;
	InitType initType;
public:
	AbstractState();
	AbstractState(unsigned int id);
	AbstractState(unsigned int id, int currentValue);
	virtual void setInitType(InitType initType);
	virtual InitType getInitType() const;
	virtual unsigned int getId() const;
	virtual int getValue() const;
	virtual void setId(unsigned int id);
	virtual void setValue(int value);
	virtual bool compare(const AbstractState& value);
	bool isInitialized();
	friend bool operator== (const AbstractState& val1, const AbstractState& val2);
	friend bool operator!= (const AbstractState& val1, const AbstractState& val2);
	friend std::ostream& operator<< (std::ostream& os, const AbstractState& val);
	friend std::istream& operator>> (std::istream& is, AbstractState* val);

};

#endif // !ABSTRACT_VALUE

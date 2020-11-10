#ifndef ABSTRACT_VALUE
#define ABSTRACT_VALUE

#include <iostream>

class AbstractState {
private:
	unsigned int id;
	int value;
	bool initialized;
public:
	AbstractState();
	AbstractState(unsigned int id);
	AbstractState(unsigned int id, int currentValue);
	virtual unsigned int getId();
	virtual int getValue();
	virtual void setId(unsigned int id);
	virtual void setValue(int value);
	virtual bool compare(const AbstractState& value);
	bool isInitialized();
	friend bool operator== (const AbstractState& val1, const AbstractState& val2);
	friend std::ostream& operator<< (std::ostream& os, const AbstractState& val);
	friend std::istream& operator>> (std::istream& is, AbstractState* val);

};

#endif // !ABSTRACT_VALUE

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

#include "Operator_Command.h"

class Subtract_Command : public Operator_Command {
public:
	Subtract_Command(Stack <int>& s);
	virtual int evaluate(int num_one, int num_two) const;
};
#endif
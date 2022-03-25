#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Operator_Command.h"

class Multiply_Command : public Operator_Command {
public:
	Multiply_Command(Stack <int>& s);
	int evaluate(int num_one, int num_two) const;
};
#endif
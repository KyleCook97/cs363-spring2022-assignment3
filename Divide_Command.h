#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Operator_Command.h"

class Divide_Command : public Operator_Command {
public:
	Divide_Command(Stack <int>& s);
	int evaluate(int num_one, int num_two) const;
};
#endif
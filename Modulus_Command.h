#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Operator_Command.h"

class Modulus_Command : public Operator_Command {
public:
	Modulus_Command(Stack <int>& s);
	int evaluate(int num_one, int num_two) const;
};
#endif
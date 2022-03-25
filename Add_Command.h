#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Operator_Command.h"

class Add_Command : public Operator_Command 
{
	public:
		Add_Command(Stack <int>& s);
		virtual int evaluate(int num_one, int num_two) const;
};
#endif

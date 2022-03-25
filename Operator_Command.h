#ifndef _OPERATOR_COMMAND_H_
#define _OPERATOR_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Operator_Command : public Command 
{
	public:
		Operator_Command(Stack <int>& s, int concrete_value);

		void execute(void);

		virtual int evaluate(int n1, int n2) const = 0;

	private:
		Stack <int>& stack_;
};
#endif
#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Number_Command : public Command{
public:
	Number_Command(Stack <int> & s, int number);

	virtual void execute(void);

private:
	Stack <int>& stack_;
	int value_;

};
#endif
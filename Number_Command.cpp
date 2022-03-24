#include "Number_Command.h"

Number_Command::Number_Command(Stack<int>& s, int number)
	:stack_(s),
	value_(number)
{
    
}

void Number_Command::execute(void)
{
	stack_.push(value_);
}
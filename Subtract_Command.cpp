#include "Subtract_Command.h"

Subtract_Command::Subtract_Command(Stack<int>& s)
	:Operator_Command(s, 1)
{
    
}

int Subtract_Command::evaluate(int num_one, int num_two) const
{
	return num_one - num_two;
}
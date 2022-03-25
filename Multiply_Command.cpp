#include "Multiply_Command.h"

Multiply_Command::Multiply_Command(Stack<int>& s)
	:Operator_Command(s, 2)
{
    
}

int Multiply_Command::evaluate(int num_one, int num_two) const
{
	return num_one * num_two;
}
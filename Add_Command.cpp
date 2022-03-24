#include "Add_Command.h"

Add_Command::Add_Command(Stack<int>& s)
	:Operator_Command(s, 1)
{
    
}

int Add_Command::evaluate(int num_one, int num_two) const
{
	return num_one + num_two;
}
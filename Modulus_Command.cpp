#include "Modulus_Command.h"

Modulus_Command::Modulus_Command(Stack<int>& s)
	:Operator_Command(s, 2)
{
    
}

int Modulus_Command::evaluate(int num_one, int num_two) const
{
	return num_one % num_two;
}
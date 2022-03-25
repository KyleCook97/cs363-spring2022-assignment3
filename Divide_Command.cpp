#include "Divide_Command.h"

Divide_Command::Divide_Command(Stack<int>& s)
	:Operator_Command(s, 2)
{
    
}

int Divide_Command::evaluate(int num_one, int num_two) const
{
	if (num_two == 0) {
		throw std::runtime_error("Attempted to divide by 0.");
	}
	return num_one / num_two;
}
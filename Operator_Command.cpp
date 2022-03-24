#include "Operator_Command.h"

Operator_Command::Operator_Command(Stack<int>& s, int concrete_value)
	:stack_(s),
	Command(concrete_value)
{
    
}

void Operator_Command::execute(void)
{
	int num_two = stack_.top();
	stack_.pop();
	int num_one = stack_.top();
	stack_.pop();
	int result = this->evaluate(num_one, num_two);
	stack_.push(result);
}

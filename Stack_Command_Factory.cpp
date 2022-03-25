#include "Stack_Command_Factory.h"

Stack_Command_Factory::Stack_Command_Factory(Stack<int>& stack)
	:stack_(stack)
{

}

Stack_Command_Factory::~Stack_Command_Factory(void)
{
    
}

Number_Command* Stack_Command_Factory::create_number_command(int num)
{
	return new Number_Command(stack_, num);
}

Add_Command* Stack_Command_Factory::create_add_command(void)
{
	return new Add_Command(stack_);
}

Subtract_Command* Stack_Command_Factory::create_subtract_command(void)
{
	return new Subtract_Command(stack_);
}

Multiply_Command* Stack_Command_Factory::create_multiply_command(void)
{
	return new Multiply_Command(stack_);
}

Divide_Command* Stack_Command_Factory::create_divide_command(void)
{
	return new Divide_Command(stack_);
}

Modulus_Command* Stack_Command_Factory::create_modulus_command(void)
{
	return new Modulus_Command(stack_);
}
#include "Calculator.h"

Calculator::Calculator()
{

}

void Calculator::run()
{
    //final result to be outputted
    Stack <int> result;

    //command factory required in the design
    Stack_Command_Factory factory = Stack_Command_Factory(result);

    //user input
    std::string input;

    bool keepGoing = true;
    
    //begin infinite loop until "QUIT" is entered by the user
    while (keepGoing)
    {
        try
        {
            input.clear();
            result.clear();

            std::cout << "\nEnter math expression or type QUIT to exit. (case-sensitive)\n";
            std::getline(std::cin, input);

            if (input == "QUIT")
            {
                keepGoing = false;
                break;
            }

            Array <Command*> postfix;

            //convert infix to postfix
            //evaluate
            convert_to_postfix(input, factory, postfix);

            //return final result
            int final_result = result.top();
            std::cout << final_result;
        }
        catch(std::exception& err)
        {
            std::cout << "An error has occured: " << err.what() << "\n";
        }
    }
}

void Calculator::convert_to_postfix(const std::string & infix, Command_Factory & factory, Array<Command*> postfix)
{
    Queue <Command*> temp_queue = Queue <Command*>();
    std::istringstream input_stream(infix);
    std::string cur_val;
    Stack <Command*> temp_operators;
    Command* cmd = 0;
    Command* temp_cmd = 0;

    //number of operators within parenthesis
    Stack <int> ops_to_pop;

    while (!input_stream.eof())
    {
        input_stream >> cur_val;

        if (cur_val == "+")
        {
            cmd = factory.create_add_command();
        }
        else if (cur_val == "-")
        {
            cmd = factory.create_subtract_command();
        }
        else if (cur_val == "*")
        {
            cmd = factory.create_multiply_command();
        }
        else if (cur_val == "/")
        {
            cmd = factory.create_divide_command();
        }
        else if (cur_val == "%")
        {
            cmd = factory.create_modulus_command();
        }
        else if (cur_val == "(")
        {
            //add 0 to the queue to show new parenthesis
			ops_to_pop.push(0);
			continue;
        }
        else if (cur_val == ")")
        {
            if (ops_to_pop.is_empty())
            {
                throw std::runtime_error("Uneven amount of parenthesis.");
            }

            register_parenthesis_operators(ops_to_pop, temp_queue, temp_operators);
            ops_to_pop.pop();

            //for when we have nested parenthesis with an operator in between
            if (!ops_to_pop.is_empty())
            {
                register_parenthesis_operators(ops_to_pop, temp_queue, temp_operators);
            }

            continue;
        }
        else
        {
            cmd = factory.create_number_command(std::stoi(cur_val));
            temp_queue.enqueue(cmd);
            continue;
        }

        //if there are parenthesis OR (if the concrete value is an operator AND (the stack is empty OR the operator is a greater precedence than the top of the stack)))
		if (!ops_to_pop.is_empty() || (cmd->get_concrete_value() > 0 && (temp_operators.is_empty() || (cmd->get_concrete_value() > temp_operators.top()->get_concrete_value())))) 
        {
			// if there are any parenthesis, update the amount of operators to pop.
			if (!ops_to_pop.is_empty()) 
            {
				int inc_val = ops_to_pop.top() + 1;
				ops_to_pop.pop();
				ops_to_pop.push(inc_val);
			}
			temp_operators.push(cmd);
		}
        else
        {
            temp_queue.enqueue(temp_operators.top());
			temp_operators.pop();
			temp_operators.push(cmd);

            //if there are any parenthesis we update the amount of operators to pop
			if (!ops_to_pop.is_empty())
            {
				int dec_value = ops_to_pop.top() - 1;
				ops_to_pop.pop();
				ops_to_pop.push(dec_value);
            }   
        }
    }

    //empty operators leftover from the stack
    while (!temp_operators.is_empty())
    {
        temp_queue.enqueue(temp_operators.top());
        temp_operators.pop();
    }

    int amount_of_operators = 0;

    //move from queue to array
    postfix.resize(temp_queue.size());
    for (int i = 0; !temp_queue.is_empty(); i++)
    {
        Command* cmd = temp_queue.dequeue();
        if (cmd->get_concrete_value() > 0)
        {
            amount_of_operators++;
        }

        postfix[i] = cmd;
    }

    //checks to see if there are no operators while also having more than one number
    if (postfix.size() > 1 && not amount_of_operators)
    {
        throw std::runtime_error("No operators were found in the expression and a multiple numbers were found.");
    }

    Array_Iterator<Command*> iterator = Array_Iterator<Command*> (postfix);
    evaluate_postfix(iterator);
}

void Calculator::evaluate_postfix(Array_Iterator<Command*>& iter)
{
	for (; !iter.is_done(); iter.advance())
    {
		(*iter)->execute();
		delete* iter;
	}
}

void Calculator::register_parenthesis_operators(Stack<int> & ops_to_pop, Queue<Command*> & temp_queue, Stack<Command*> & temp_operators)
{
	int num_of_ops_to_pop = ops_to_pop.top();

	while (num_of_ops_to_pop > 0)
    {
		temp_queue.enqueue(temp_operators.top());
		temp_operators.pop();
		num_of_ops_to_pop--;
	}

	//for when we have nested parenthesis
	ops_to_pop.pop(); 
	ops_to_pop.push(num_of_ops_to_pop);
}
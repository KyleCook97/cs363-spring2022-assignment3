#ifndef _COMMAND_FACTORY_H_
#define _COMMAND_FACTORY_H_

#include <string>	//for input
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"

class Command_Factory {
	public:
        //default constructor
		Command_Factory();  

        //destructor
		virtual ~Command_Factory(void);

        //number command
		virtual Number_Command* create_number_command(int num) = 0;

        //add command
		virtual Add_Command* create_add_command(void) = 0;

        //subtract command
		virtual Subtract_Command* create_subtract_command(void) = 0;

        //mulitply command
		virtual Multiply_Command* create_multiply_command(void) = 0;

        //divide command
		virtual Divide_Command* create_divide_command(void) = 0;

        //modulus command
		virtual Modulus_Command* create_modulus_command(void) = 0;

};
#endif
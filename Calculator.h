#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>          //for input
#include <iostream>        //for cout
#include <sstream>		   //for istringstream
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Command.h"
#include "Command_Factory.h"
#include "Stack_Command_Factory.h"
#include "Array_Iterator.h"

class Calculator 
{
    public:
        //default constructor
        Calculator (void);

        /**
         * Function used to handle reading in input
         * as well as outputting the result of the expression
         * 
         * In order to exit you must type "QUIT" and is case-sensitive
         */
        void run();

    private:
        /*
        * Converts the infix string to postfix
        *
        * @param[in]      infix		     String for infix
        * @param[in]      factory        Factory creating all commands
        * @param[in]      postfix        Array holding all commands
        */
		void convert_to_postfix(const std::string & infix, Command_Factory & factory, Array<Command*> postfix);

		/*
		* Executes the array of commands
        *
		* @param[in]      iter        Iterator
		*/
		void evaluate_postfix(Array_Iterator<Command*>& iter);

		/*
		* Moves operators within parenthesis into a temporary
        * queue that will be executed once a closing parenthesis is reached
        * 
		* @param[in]  operators_to_pop		    Stack holding the operators to pop. Includes parenthesis
		* @param[in]  temp_queue				Temp queue holding commands
		* @param[in]  temp_operators			Stack containing operators
		*/
		void register_parenthesis_operators(Stack <int> & operators_to_pop, Queue<Command*> & temp_queue, Stack <Command*> & temp_operators);
};
#endif
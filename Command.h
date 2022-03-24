#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command
{
    public:
        //default constructor
        Command (void);

        Command (int concrete_value);

        //destructor
        ~Command (void);

        virtual void execute (void) = 0;

        //gets the value that the concrete type is assigned to
        int get_concrete_value();

    private:
        //represents the heirarchy of the operators
        int concrete_value_; 
};
#endif
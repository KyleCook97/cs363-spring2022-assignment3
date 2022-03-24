#include "Command.h"

Command::Command()
    :concrete_value_(0)
{

}

Command::Command(int concrete_value)
    :concrete_value_(concrete_value)
{

}

Command::~Command(void)
{
    //destructor
}

int Command::get_concrete_value()
{
    return concrete_value_;
}
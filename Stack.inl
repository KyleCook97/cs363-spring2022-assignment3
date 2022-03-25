// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

#include <iostream>

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    std::cout<<"Check empty"<<std::endl;
    is_stack_empty();
    std::cout<<"Is not empty"<<std::endl;
    return arr_[size_];
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    return size_ == 0;
}

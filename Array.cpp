// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

#define DEFAULT_SIZE 10

//
// Array
//
template <typename T>
Array <T>::Array (void)
    :max_size_(DEFAULT_SIZE),
    cur_size_(DEFAULT_SIZE)
{
    
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
    :max_size_(length),
    cur_size_(length),
    Basic_Array<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
    :max_size_(length),
    cur_size_(length),
    Basic_Array<T>(length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
    :max_size_(array.max_size_),
    cur_size_(array.cur_size_),
    Basic_Array<T>(array.max_size_)
{
    *this = array;
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    //destructor is called from parent class
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    //check to self assignment
    if(this != &rhs)
    {
        return *this;
    }

    if(this->max_size_ < rhs.size())
    {
        delete [] this->data_;
        this->data_ = new T[rhs.size()];
    }

    this->cur_size_ = rhs.size();
    this->max_size_ = rhs.size();

    for(size_t i = 0; i < this->cur_size_; i++)
    {
       this->data_[i] = rhs.data_[i];
    }
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
    //check to see if the index given is out of the range of the array
    //if the index is out of range throw an exception 
    try
    {
        if(index < 0 || index > max_size_)
        {
            throw "Invalid index";
        }
    }
    catch(const std::out_of_range& oor)
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

    return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    //check to see if the index given is out of the range of the array
    //if the index is out of range throw an exception 
    try
    {
        if(index < 0 || index > max_size_)
        {
            throw "Invalid index";
        }
    }
    catch(const std::out_of_range& oor)
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

    return data_[index];

}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    //if no resize then do nothing
    if (new_size == cur_size_)
    {
        return;
    }

    if (new_size < max_size_)
    {
        cur_size_ = new_size;
    }

    if (new_size > max_size_)
    {
        Array copy = Array<T>(new_size);

        for(size_t i = 0; i < new_size; i++)
        {
            copy[i] = this->data_[i];
        }

        *this = copy;
    }
}


//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
    //self comparison
    if (this == &rhs)
    {
        return true;
    }

    //array sizes do not match
    if (this->cur_size_ != rhs.size())
    {   
        return false;
    }

    //values in array do not match
    for(size_t i = 0; i < this->cur_size_; i++)
    {
        if (this->data_[i] != rhs[i])
        {
            return false;
        }
    }
    return true;    
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
    //self comparison
    if (!(this == &rhs))
    {
        return true;
    }

    //array sizes do not match
    if (!(this->cur_size_ != rhs.size()))
    {   
        return false;
    }

    //values in array do not match
    for(size_t i = 0; i < this->cur_size_; i++)
    {
        if (!(this->data_[i] != rhs[i]))
        {
            return false;
        }
    }
    return true;   
}

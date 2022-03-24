// -*- C++ -*-

//==============================================================================
/**
 * @file       Basic_Array.cpp
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#include "Basic_Array.h"

#define DEFAULT_SIZE 10

//
// Basic_Array
//
template <typename T>
Basic_Array <T>::Basic_Array(void)
    :size_(DEFAULT_SIZE),
    data_(new T[DEFAULT_SIZE])
{

}

//
// Basic_Array (size_t)
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length)
    :size_(length),
    data_(new T[length])
{

}

//
// Basic_Array (size_t, char)
//
template <typename T>
Basic_Array <T>::Basic_Array (size_t length, T fill)
    :size_(length),
    data_(new T[length])
{
    //fill the array with the char passed into it
    this->fill(fill);
}

//
// Array (const Array &)
//
template <typename T>
Basic_Array<T>::Basic_Array(const Basic_Array & array)
    :size_(array.size_),
    data_(new T[array.size_])
{
    for (size_t i = 0; i < size_; i++)
    {
        data_[i] = array[i];
    }
}

//
// ~Basic_Array
//
template <typename T>
Basic_Array<T>::~Basic_Array(void)
{
    delete[] data_;
}

//
// operator =
//
template <typename T>
const Basic_Array <T> & Basic_Array <T>::operator = (const Basic_Array & rhs)
{
    //check to self assignment
    if(this != &rhs)
    {
        return *this;
    }

    if(this->size_ < rhs.size())
    {
        delete [] this->data_;
        this->data_ = new T[rhs.size()];
    }

    this->size_ = rhs.size();

    for(size_t i = 0; i < this->size_; i++)
    {
       this->data_[i] = rhs.data_[i];
    }
}

//
// operator []
//
template <typename T>
T & Basic_Array <T>::operator [] (size_t index)
{
    //check to see if the index given is out of the range of the array
    //if the index is out of range throw an exception 
    try
    {
        if(index < 0 || index > size_)
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
const T & Basic_Array <T>::operator [] (size_t index) const
{
    //check to see if the index given is out of the range of the array
    //if the index is out of range throw an exception 
    try
    {
        if(index < 0 || index > size_)
        {
            throw "Invalid index";
        }
    }
    catch(const std::out_of_range& oor)
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

    //loop through array until you get to the index indicated
    for(size_t i = 0; i < index; i++) 
    {
        if(data_[i] == index) 
        {
            std::cout<<this->data_[i]<<std::endl;
        }
    } 

}


//
// get
//
template <typename T>
T Basic_Array <T>::get (size_t index) const
{
    try
    {
        if(index < 0 || index > size_)
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
// set
//
template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{
    try
    {
        if(index < 0 || index > size_)
        {
            throw "Invalid index";
        }
    }
    catch(const std::out_of_range& oor)
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

    this->data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Basic_Array <T>::find (T value) const
{
    for(size_t i = 0; i < this->size_; i++)
    {
        if (data_[i] == value)
        {
            return i;
        }
    }

    //not found
    return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Basic_Array <T>::find (T val, size_t start) const
{
    try
    {
        if(start < 0 || start > size_)
        {
            throw "Invalid index";
        }
    }
    catch(const std::out_of_range& oor)
    {
        std::cout<<"Invalid index value"<<std::endl;
    }

    for(size_t i = start; i < this->size_; i++)
    {
        if (data_[i] == val)
        {
            return i;
        }
    }

    //not found
    return -1;

}

//
// operator ==
//
template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const
{
    //self comparison
    if (this == &rhs)
    {
        return true;
    }

    //array sizes do not match
    if (this->size_ != rhs.size())
    {   
        return false;
    }

    //values in array do not match
    for(size_t i = 0; i < this->size_; i++)
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
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const
{
    //self comparison
    if (!(this == &rhs))
    {
        return true;
    }

    //array sizes do not match
    if (!(this->size_ != rhs.size()))
    {   
        return false;
    }

    //values in array do not match
    for(size_t i = 0; i < this->size_; i++)
    {
        if (!(this->data_[i] != rhs[i]))
        {
            return false;
        }
    }
    return true;   
}

//
// fill
//
template <typename T>
void Basic_Array <T>::fill (T value)
{
    for(size_t i = 0; i < this->size_; i++)
    {
        this->data_[i] = value;
    }
}

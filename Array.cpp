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
Array <T>::Array (const Array <T> & array)
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
const Array <T> & Array <T>::operator = (const Array <T> & rhs)
{
    if (this != &rhs)
    {
        Basic_Array<T>::operator=(rhs);
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
    }

    return *this;
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

    if (max_size_ >= new_size)
    {
        cur_size_ = new_size;
    }

    if (new_size > max_size_)
    {
        copy_data(new_size);
    }
}

template <typename T>
void Array <T>::copy_data(size_t length)
{
    // this method is always called when the length is greater than the maximum size
    // of the current array

    Array temp_arr = Array<T>(length);

    // copy data
    for (size_t i = 0; i < max_size_; i++)
    {
        temp_arr[i] = (*this)[i];
    }

    // replace the current array with an array that allocated space.
    *this = temp_arr;

    cur_size_ = length;
    if (cur_size_ > max_size_) {
        max_size_ = cur_size_;
    }

}
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
    delete_data();
}

//
// operator =
//
template <typename T>
const Basic_Array <T> & Basic_Array <T>::operator = (const Basic_Array & rhs)
{
    if (this != &rhs)
    {
        delete_data();
        size_ = rhs.size_;
        data_ = new T[size_];

        for (size_t i = 0; i < size_; i++)
        {
            data_[i] = rhs[i];
        }
    }
}

//
// operator []
//
template <typename T>
T & Basic_Array <T>::operator [] (size_t index)
{
    return get_char_from_index(index);
}

//
// operator [] 
//
template <typename T>
const T & Basic_Array <T>::operator [] (size_t index) const
{
    return get_char_from_index(index);
}

//
// get
//
template <typename T>
T Basic_Array <T>::get (size_t index) const
{
    return get_char_from_index(index);
}

//
// set
//
template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{
    check_out_of_range(index);
    data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Basic_Array <T>::find (T val) const
{
    return get_index_from_char(val, 0);
}

//
// find (char, size_t) 
//
template <typename T>
int Basic_Array <T>::find (T val, size_t start) const
{
    check_out_of_range(start);
    return get_index_from_char(val, start);
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
    if (size_ != rhs.size())
    {   
        return false;
    }

    //values in array do not match
    for(size_t i = 0; i < size_; i++)
    {
        if (data_[i] != rhs[i])
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
    return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Basic_Array <T>::fill (T value)
{
    for(size_t i = 0; i < size_; i++)
    {
        data_[i] = value;
    }
}

template <typename T>
void Basic_Array <T>::check_out_of_range (size_t index) const
{
    if (index >= size_ || index < 0)
    {
        throw std::out_of_range("Array Index is out of range.");
    }
}

template <typename T>
T & Basic_Array <T>::get_char_from_index (size_t index) const
{
    check_out_of_range(index);
    return data_[index];
}

template <typename T>
int Basic_Array <T>::get_index_from_char (T ch, size_t start) const
{
    for (size_t i = start; i < size_; i++)
    {
        if (data_[i] == ch)
        {
            return i;
        }
    }
    //if no char is found
    return -1; 
}

template <typename T>
void Basic_Array <T>::delete_data()
{
    delete[] data_;
    data_ = nullptr;
}

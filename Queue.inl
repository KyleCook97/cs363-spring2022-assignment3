// -*- C++ -*-
// $Id: Queue.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
//size
//
template <typename T>
inline
size_t Queue <T>::size (void) const
{
    return this->size_;
}

//
//is_empty
//
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    return (size() == 0);
}

//
//front
//
template <typename T>
inline
T Queue <T>::front (void) const
{
    is_queue_empty();
    return arr_[front_of_queue_];
}
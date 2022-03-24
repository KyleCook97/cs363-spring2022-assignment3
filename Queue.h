// -*- C++ -*-
// $Id: Queue.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include <exception>
#include <iostream>
#include <cstring>          // for size_t definition


/**
 * @class Queue
 * 
 * Basic Queue for arbitrary elements.
 */
template <typename T>
class Queue
{
    public:
    /// Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     * 
     * Exception thrown to indicate the queue is empty.
     */
    class empty_exception : public std::exception
    {
        public:
        /// Default constructor.
        empty_exception (void)
            : std::exception () { }

        /**
         * Initialization constructor.
         * 
         * @param[in]       msg         Error message.
         */
        empty_exception (const char * msg)
            : std::exception (msg) { }
    };

    /// Default constructor.
    Queue (void);

    /// Copy constructor.
    Queue (const Queue & s);

    /// Destructor.
    ~Queue (void);
    
    /**
    * Assignment operator
    *
    * @param[in]      rhs           Right-hand side of operator
    * @return         Reference to self
    */
    const Queue & operator = (const Queue & rhs);

    /**
    * Push a new element into the Queue. The element is inserted
    * before all the other elements in the list.
    *
    * @param[in]      element       Element to add to the list
    */
    void enqueue (T element);

    /**
    * Remove the first element from the queue.
    *
    * @exception      empty_exception    The Queue is empty.
    */
    T dequeue (void);

    /**
    * Get the first element in the queue. If there are no elements 
    * on the queue, then the queue_is_empty exception is thrown.
    *
    * @return         Element in the front of the queue.
    * @exception      empty_exception    The queue is empty
    */
    T front (void) const;

    /**
    * Test if the Queue is empty
    *
    * @retval         true          The Queue is empty
    * @retval         false         The Queue is not empty
    */
    bool is_empty (void) const;

    /**
    * Retrieve the current size of the Queue.
    *
    * @return          The current size
    */
    size_t size (void) const;

    /// Remove all elements from the Queue.
    void clear (void);

    private:
    // add member variable here
    /*
    * Raises an exception if the stack is empty
    * @exception      empty_exception    The stack is empty
    */
    void is_queue_empty() const;

    Array <T> arr_;

    /// index of the front of the queue
    size_t front_of_queue_;

    /// size of queue
    size_t size_;

    /// used in resizing the array
    size_t inc_amt_ = 1;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif // !defined _QUEUE_H
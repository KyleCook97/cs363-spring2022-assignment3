// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
// COMMENT This initialization is not necessary because you are actually
// calling the copy constructor using a temporary object.

//RESPONSE Removed explicit calling of a constructor.
    :size_(0)
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
// COMMENT This initialization is not necessary because you are actually
// calling the copy constructor using a temporary object.

//RESPONSE Removed explicit calling of a constructor.
    :size_(0)
{
    *this = stack;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //destructor is called from parent class
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    std::cout<<"checking stack size"<<std::endl;
    //if there is not enough space we resize the array to make more room
    if (this->size_ <= size_)
    {
        std::cout<<"resizing stack"<<std::endl;
        arr_.resize(this->size_ + inc_amt_);
        std::cout<<"stack resized"<<std::endl;
    }

    std::cout<<"adding element to stack"<<std::endl;
    arr_.set(this->size_, element);
    std::cout<<"increasing size of the stack"<<std::endl;
    this->size_++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    // COMMENT The name of the method within this context makes it seems
    // as if you are emptyig the stack! Come up with a better name so it
    // does not give this appearance unless you actually look at the
    // method's implementation.

    //RESPONSE Renamed the method to be more clear.
    is_stack_empty();

    //the top of the stack gets overwritten when
    //we make the stack size smaller
    size_--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (this != &rhs)
    {
        // COMMENT It would be easier if you just use the assignment operator
        // on the array to copy things from rhs.
        
        //first we will clear out the stack
        //then set its size to the rhs then we
        //copy all the values over from the rhs
        clear();
        size_t rhs_size = rhs.size();
        arr_.resize(rhs_size);

        if (!rhs.is_empty())
        {
            for(size_t i = rhs_size - 1; i >= 0; i--)
            {
                push(rhs.arr_[i]);

                //size_t values can never be negative so we gotta kick it out manually
                if (i == 0)
                {
                    break;
                }
            }
        }

    }
    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //because the objects will be overwritten when
    //we resize the stack, we can just resize it back to 0
    arr_.resize(0);
    size_ = 0;
}

//
// check if the stack is empty
//
template <typename T>
void Stack <T>::is_stack_empty() const
{
	if (size_ == 0)
    {
		throw empty_exception();
	}
}

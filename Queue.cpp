// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>
//
// Queue
//
template <typename T>
Queue <T>::Queue (void)
// COMMENT You are using the copy constructor to initialize the array. There
// is no need to explicitly call a constuctor if you are going to use the
// default constructor to initilize the member variable.

//RESPONSE Removed explicit calling of a constructor.
	:size_(0),
	front_of_queue_(0)
{

}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue& queue)
// COMMENT You are using the copy constructor to initialize the array. There
// is no need to explicitly call a constuctor if you are going to use the
// default constructor to initilize the member variable.

//RESPONSE Removed explicit calling of a constructor.
	:size_(0),
	front_of_queue_(0)
{
	*this = queue;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue(void)
{
    //destructor is called from parent class
}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
    // COMMENT You are resizing the queue, but you are wasting space at the front of
    // the array. Fix your design so you use all the space in the array.

    //RESPONSE The size of the queue no longer increases if its size is <= the size and
	// now only when it is <.

	//if there is not enough space we resize the array to make more room
	if (arr_.size() < size_)
    {
		arr_.resize(size_ + inc_amt_);
	}
	arr_.set(size_, element);
	size_++;
}

//
// dequeue
//
template <typename T>
T Queue <T>::dequeue(void)
{
    // COMMENT This solution will work, but you are wasting space at the front
    // of the array since those "unused" spaces will never be used again. Please
    // come up with a better design that uses memory more efficiently.

    //RESPONSE Corrected the else statment to properly get rid of "unused" space.
	T value_in_front = front();  

	//if elemenet is last in queue
	if (size_ == 1)
    {
		clear();  
	}
	else
    {
		front_of_queue_++;
		size_--;
		
	}
	return value_in_front;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if (this != &rhs)
    {
        //first we will clear out the queue
        //then set its size to the rhs then we
        //copy all the values over from the rhs
		clear();
		size_t rhs_size = rhs.size();
		arr_.resize(rhs_size);

		if (!rhs.is_empty())
        {
			//opposite of stack, we start at 0
			for (size_t i = 0; i < rhs_size; i++)
            {
				enqueue(rhs.arr_[i + rhs.front_of_queue_]);
			}
		}
	}
	return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
    //because the objects will be overwritten when
    //we resize the stack, we can just resize it back to 0
	arr_.resize(0);
	size_ = 0;
	front_of_queue_ = 0;
}

//
// check if the queue is empty
//
template <typename T>
void Queue <T>::is_queue_empty() const
{
	if (size_ == 0)
    {
		throw empty_exception();
	}
}

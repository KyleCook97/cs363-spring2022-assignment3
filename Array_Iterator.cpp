#include "Array_Iterator.h"

template<typename T>
Array_Iterator<T>::Array_Iterator(Array<T>& arr)
	:arr_(arr),
	cur_(0)
{

}

template<typename T>
Array_Iterator<T>::~Array_Iterator(void)
{
    
}

template<typename T>
bool Array_Iterator<T>::is_done(void)
{
	return cur_ >= arr_.size();
}

template<typename T>
void Array_Iterator<T>::advance(void)
{
	++cur_;
}

template<typename T>
T& Array_Iterator<T>::operator*(void)
{
	return arr_[cur_];
}

template<typename T>
T* Array_Iterator<T>::operator->(void)
{
	return arr_[cur_];
}

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"

template <typename T>
class Array_Iterator {
public:
	Array_Iterator(Array <T>& arr);
	~Array_Iterator(void);

	bool is_done(void);
	void advance(void);

	T& operator * (void);
	T* operator -> (void);
private:
	Array <T>& arr_;
	size_t cur_;
};

#include "Array_Iterator.cpp"
#endif
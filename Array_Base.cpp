#include "Array_Base.h"

template <typename T>
Array_Base <T> ::Array_Base(void)
    :size_(0),
    data_(new T[0])
{
}

template <typename T>
Array_Base<T>::Array_Base(size_t length)
    :size_(length),
    data_(new T[length])
{
}

template <typename T>
Array_Base<T>::Array_Base(size_t length, T fill)
    :size_(length),
    data_(new T[length])
{
    this->fill(fill); // fill the array with the char passed in. 
}

template <typename T>
Array_Base<T>::Array_Base(const Array_Base& array)
    :size_(array.size_),
    data_(new T[array.size_])
{
    // copy data of the passed in array.
    for (size_t i = 0; i < size_; i++) {
        data_[i] = array[i];
    }
}

template <typename T>
Array_Base<T>::~Array_Base(void)
{
    destroy_data();
}

template <typename T>
const Array_Base<T>& Array_Base<T>::operator = (const Array_Base<T> & rhs)
{
    if (this != &rhs) {
        destroy_data();
        size_ = rhs.size_;
        data_ = new T[size_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = rhs[i];
        }
    }
    return *this;
}

template <typename T>
T& Array_Base<T>::operator [] (size_t index)
{
    return get_char_from_index(index);
}

template <typename T>
const T& Array_Base<T>::operator [] (size_t index) const
{
    return get_char_from_index(index);
}

template <typename T>
T Array_Base<T>::get(size_t index) const
{
    return get_char_from_index(index);
}

template <typename T>
void Array_Base<T>::set(size_t index, T value)
{
    check_out_of_range(index);
    data_[index] = value;
}

template <typename T>
int Array_Base<T>::find(T ch) const
{
    return get_index_from_char(ch, 0);
}

template <typename T>
int Array_Base<T>::find(T ch, size_t start) const
{
    check_out_of_range(start);
    return get_index_from_char(ch, start);
}

template <typename T>
bool Array_Base<T>::operator == (const Array_Base<T>& rhs) const
{
    if (this == &rhs) {
        // self comparison
        return true;
    }

    // if the array current sizes do not match
    if (size_ != rhs.size_) {
        return false;
    }

    // if the data points do not match accordingly
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
bool Array_Base<T>::operator != (const Array_Base<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
void Array_Base<T>::fill(T ch)
{
    for (size_t i = 0; i < size_; i++){
        data_[i] = ch;
    }
}

template <typename T>
void Array_Base<T>::reverse(void)
{
    // if the current size is 0 or 1, then there is nothing to reverse.
    if (size_ == 0 || size_ == 1) {
        return;
    }

    size_t lower_index = 0;
    size_t higher_index = size_ - 1;

    bool keep_going = true;
    while (keep_going) {
        T temp_char = data_[lower_index];  // holds the char temporarily.
        data_[lower_index] = data_[higher_index];
        data_[higher_index] = temp_char;
        
        lower_index++;
        higher_index--;
        if (lower_index == higher_index || lower_index > higher_index) {
            keep_going = false;
        }
    }
}

template <typename T>
Array_Base<T> Array_Base<T>::slice(size_t begin) const
{
    return slice(begin, size_);
}

template <typename T>
Array_Base<T> Array_Base<T>::slice(size_t begin, size_t end) const
{
    if (begin == 0 && end == 0) {
        // equivalent of returning an empty array 
        return Array_Base<T>(end);
    }
    check_out_of_range(begin);  // check for issue with begin input
    check_out_of_range(end - 1);  // check for issue with end input
    Array_Base<T> copied_array = Array_Base<T>(end - begin);
    size_t new_array_index = 0;
    for (size_t i = begin; i < end; i++) {
        copied_array[new_array_index] = data_[i];
        new_array_index++;
    }
    return copied_array;
}

template <typename T>
void Array_Base<T>::check_out_of_range(size_t index) const {
    if (index >= size_ || index < 0) {
        throw std::out_of_range("Array Index is out of range.");
    }
}

template <typename T>
T& Array_Base<T>::get_char_from_index(size_t index) const {
    check_out_of_range(index);
    return data_[index];
}

template <typename T>
void Array_Base<T>::destroy_data() {
    delete[] data_;
    data_ = nullptr;
}

template <typename T>
int Array_Base<T>::get_index_from_char(T ch, size_t start) const {
    for (size_t i = start; i < size_; i++) {
        if (data_[i] == ch) {
            return i;
        }
    }
    return -1; // no char found.
}
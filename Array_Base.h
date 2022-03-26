#ifndef _ARRAY_BASE_H_
#define _ARRAY_BASE_H_

#include <cstring>          // for size_t definition
#include <iostream>         // for cout.
#include <stdexcept>        // for out_of_range exception.


/**
 * @class Array_Base
 * 
 * The general Array structure without resize or shrink.
 */
template <typename T>
class Array_Base
{
public:
    /// Default constructor.
    Array_Base(void);

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     */
    Array_Base(size_t length);

    /**
     * Initializing constructor.
     *
     * @param[in]      length        Initial size
     * @param[in]      fill          Initial value for each element
     */
    Array_Base(size_t length, T fill);

    /**
     * Copy constructor
     *
     * @param[in]     arr         The source array.
     */
    Array_Base(const Array_Base<T>& arr);

    /// Destructor.
    ~Array_Base(void);

    /**
     * Assignment operation
     *
     * @param[in]       rhs      Right-hand side of equal sign
     * @return          Reference to self
     */
    const Array_Base<T>& operator = (const Array_Base<T>& rhs);

    /**
     * Retrieve the current size of the array.
     *
     * @return          The current size
     */
    virtual size_t size(void) const;

    /**
     * Get the character at the specified index. If the index is not
     * within the range of the array, then std::out_of_range exception
     * is thrown.
     *
     * @param[in]       index               Zero-based location
     * @return          Character at \index
     * @exception       std::out_of_range   Invalid \a index value
     */
    T& operator [] (size_t index);

    /**
     * @overload
     *
     * The returned character is not modifiable.
     */
    const T& operator [] (size_t index) const;

    /**
     * Get the character at the specified index. If the \a index is not within
     * the range of the array, then std::out_of_range exception is thrown.
     *
     * @param[in]       index                 Zero-based location
     * @return          Character at \index
     * @exception       std::out_of_range     Invalid index value
     */
    T get(size_t index) const;

    /**
     * Set the character at the specified \a index. If the \a index is not
     * within range of the array, then std::out_of_range exception is
     * thrown.
     *
     * @param[in]       index                 Zero-based location
     * @param[in]       value                 New value for character
     * @exception       std::out_of_range     Invalid \a index value
     */
    void set(size_t index, T value);

    /**
     * Locate the specified character in the array. The index of the first
     * occurrence of the character is returned. If the character is not
     * found in the array, then -1 is returned.
     *
     * @param[in]        ch        Character to search for
     * @return           Index value of the character
     * @retval           -1        Character not found
     */
    int find(T ch) const;

    /**
     * @overload
     *
     * This version allows you to specify the start index of the search. If
     * the start index is not within the range of the array, then the
     * std::out_of_range exception is thrown.
     *
     * @param[in]       ch                   Character to search for
     * @param[in]       start                Index to begin search
     * @return          Index value of first occurrence
     * @retval          -1                   Character not found
     * @exception       std::out_of_range    Invalid index
     */
    int find(T ch, size_t start) const;

    /**
     * Test the array for equality.
     *
     * @param[in]       rhs                  Right hand side of equal to sign
     * @retval          true                 Left side is equal to right side
     * @retval          false                Left side is not equal to right side
     */
    bool operator == (const Array_Base<T>& rhs) const;

    /**
     * Test the array for inequality.
     *
     * @param[in]       rhs                  Right-hand size of not equal to sign
     * @retval          true                 Left side is not equal to right side
     * @retval          false                Left size is equal to right side
     */
    bool operator != (const Array_Base<T>& rhs) const;

    /**
     * Fill the contents of the array.
     *
     * @param[in]       ch                   Fill character
     */
    void fill(T ch);

    /// Reverse the contents of the array such that the first element is now
    /// the last element and the last element is the first element.
    void reverse(void);


    /**
     * The slice() method returns a shallow copy of a portion of an array into
     * a new array object selected from begin to end (end not included). The original
     * array will not be modified.
     *
     * @param[in]       begin           The starting index
     * @return          A new Array object
     * @exception       std::out_of_range     Invalid index value
     */
    Array_Base<T> slice(size_t begin) const;

    /**
     * @overload
     *
     * @param[in]       begin           The starting index
     * @param[in]       end             The ending index
     * @return          A new Array object
     * @exception       std::out_of_range     Invalid index value
     */
    Array_Base<T> slice(size_t begin, size_t end) const;

private:
    //////////////////////////////////////////////////////////////////////////////
    /// DEFINE ANY HELPER METHODS HERE

    /**
     * @overload
     *
     * Get the index of the first occurring char.
     *
     * @param[in]       ch                   Character to search for
     * @param[in]       start                Index to begin search
     * @return          Index value of first occurrence
     * @retval          -1                   Character not found
     */
    int get_index_from_char(T ch, size_t start) const;

    /*
    * Method for resetting data values, equivalent to calling destructor
    * without actually destroying the Array object.
    */
    void destroy_data();

    /*
    * Raises an exception if the input value is out of range.
    * @param[in]       index                 Zero-based location
    * @exception       std::out_of_range     Invalid index value
    */
    void check_out_of_range(size_t index) const;

    /*
    * Gets the character based on the index.
    * Raises an exception if the input value is out of range.
    * @param[in]       index                 Zero-based location
    * @return          Character at \index
    * @exception       std::out_of_range     Invalid index value
    */
    T& get_char_from_index(size_t index) const;

    //////////////////////////////////////////////////////////////////////////////
    
    /// Pointer to the actual data.
    T* data_;

    size_t size_; // size of the array



};

#include "Array_Base.inl"

// include the source file since template class
#include "Array_Base.cpp"

#endif   // !defined _ARRAY_BASE_H_

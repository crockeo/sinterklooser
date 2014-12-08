#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

//////////
// Code //

// A class similar to the built in array except with some more helper functions
// to go along with it.
template<class T>
class Array {
public:
    // Constructing an array from a set of values and their size. Something to
    // note is that it doesn't actually refer to the object that's passed in. It
    // instead takes a copy of the element.
    Array(T*, int);

    // Constructing an array from a pre-determined
    Array(int);

    // Constructing an array with the default size (of 2).
    Array();

    // Accessing an element in the array.
    T at(int);
    T operator[](int);

    // Pushing a value onto the left side of the array O(n) amortized time.
    void pushLeft(T);

    // Pushing a value onto the right side of the array O(1) amortized time.
    void pushRight(T);

    // Expanding the array's memory size to 2x the current size.
    int expand();

    // Getting the size of the array.
    int getSize();

    // Getting the length of the array.
    int getLength();
private:
    int size, length;
    T* ts;
};

#include "array.cpp"

#endif

#include <stdbool.h>

// Exercise 1:
// why is sizeof(a) / sizeof(type) inferior to sizeof(a)/sizeof(a[0])?
//
// Because it couples the sizeof calculation to the array definition.
// If you refactor the array to go from int to long int, then you'd
// need to update all your size calculations. By referencing the 0th
// element, C's strict type system guarantees that you will always get
// the correct type and size

// Exercise 2:
// How can you use a digit (a char) as an array subscript?
//
// Since `char` is really an int, you can subtract the appropriate offset
// to map '0' ... '9' to 0 ... 9
//
// char subscript = '4';
// printf(my_array[(int)subscript - (int)'0']);
//
// The casting is all necessary, but it's included here for clarity

// Exercise 3:
// Write a declaration of an array named `weekend` containing seven
// bool values. Include an initializer that makes the first and last
// values true; all other values should be false;
//
bool weekend[7] = {[0] = true, [6] = true};

// Exercise 4:
// Repeat ex 3, but this time use a C99 designated initializer. Make it as
// short as possible.
//
// That's actually what I did already. So, I'll make an explicit initializer
// this time:
bool wkend[7] = {true, false, false, false, false, false, true};

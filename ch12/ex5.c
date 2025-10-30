#include <stdio.h>
#include <stdlib.h>

// Suppose that a is a 1D array and p is a pointer variable.
// Assiming that the assignment p = a has just been performed,
// which of the following expressions are illegal because of
// mismatched types?
//
// Of the remeaining expressions, which are true (have nonzero value)?


int main() {
  int a[100];
  int *p = a;

  puts("(a) p == a[0]");
  // This should be true, since a[0] is the same as a, which is actually
  // just a pointer itself to its own first element.
  puts("\tThis should be true");
  (p == a) ? puts("\tTrue") : puts("\tFalse");

  puts("\n(b) p == &a[0]");
  // This should also be true, since the address of a[0] is the address
  // of the first element, which is what the pointer a actually points
  // to. The & is unneeded
  puts("\tThis should be true");
  (p == &a[0]) ? puts("\tTrue") : puts("\tFalse");

  puts("\n(c) *p == a[0]");
  // This should also be true. It asks if the value at the pointer's 
  // target is equal to the value of a's first element. Since p points
  // to a's first element, this is true (note, we have not actually put
  // values in the array, so there will just be random memory contents)
  puts("\tThis should be true");
  (*p == a[0]) ? puts("\tTrue") : puts("\tFalse");

  puts("\n(d) p[0] == a[0]");
  // Hmmm... gotta really think about this for a minute...
  //
  // is p[0] valid syntax? I'm tempted to say yes, since the array
  // variable a[] is actually a pointer to a[0]... I'm going for it.
  // If the syntax is valid, then the expression is True.
  puts("\tThis should be true");
  (p[0] == a[0]) ? puts("\tTrue") : puts("\tFalse");


  return EXIT_SUCCESS;
}

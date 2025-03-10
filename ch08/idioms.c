#include <stdio.h>
#include <string.h>

#define N 10
#define SIZE ((int)(sizeof(a) / sizeof(a[0])))

int main(int argc, char *argv[]) {
  int a[N];
  int i;

  for (i = 0; i < N; i++)
    a[i] = 0; /* clears a[] */

  for (i = 0; i < N; i++)
    scanf("%d", &a[i]); // reads data into a[]

  int sum = 0;
  for (i = 0; i < N; i++) {
    sum += a[i]; // sums the elements of a[]
  }

  // Array initialization
  int b[N] = {0}; // initialize all values to 0
  int c[N] = {[2] = 29, [9] = 7};
  // c is initialized to {0e 0, 29, 0, 0, 0, 0, 0, 0, 7}

  int d[N] = {5, 1, 9, [4] = 3, 7, 2};
  // d is initialized to {5, 1, 9, 0, 3, 7, 2, 0, 0, 0}

  // Determining the sizes of arrays:
  //
  // sizeof(a) returns the number of bytes in the array. Dividing by the
  // number of bytes in an array element gives the number of elements. Arrays
  // are guaranteed to have element 0 (must have at least one element)
  size_t array_size = sizeof(a) / sizeof(a[0]);

  // If using in a for-loop, some compilers will give an error because sizeof
  // returns a `size_t` - so using in a comparison like : i < sizeof  might be
  // flagged as dangerous for comparing a signed intege4r to an unsigned int.
  //
  // THis is not actually dangerous, because both are guaranteed to be positive
  // but warnings can be silenced by casting sizeof to an int
  for (i = 0; i < (int)sizeof(a) / sizeof(a[0]); i++) {
    // Do stuff to the entire array
  }

  // We can use a macro, like SIZE (above) to keep it terse. To be really
  // useful, we would need to add a parameter to the macro. For now, this at
  // least lets us change the size of array a[] without breaking loops
  for (i = 0; i < SIZE; i++) {
    // Loop over the entire array
  }

  // Array assignment
  // a = b
  // This is NOT legal, because a and b are actually pointers to the memory
  // that stores the arrays. So, the above does not make the contents of a
  // the same as b's.
  //
  // To copy array contents, the simplest way is to loop through and assign
  // each element. Otherwise, you can use `memcpy` from <string.h>
  memcpy(a, b, sizeof(a));

  return 0;
}

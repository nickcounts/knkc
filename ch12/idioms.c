#include <stdio.h>
#include <stdlib.h>

void sec_12_1(void) {
  // Pointers and Arrays
  printf("12.1: Pointer Arithmetic\n----------------------------\n");

  int a[10], *p, *q, i;

  // We can make p point to a[0] by writing:
  p = &a[0];

  // p [ ]
  //    v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  // We can now access a[0] throught p. For example, we can store `5` in
  // a[0] by
  *p = 5;

  // p [ ]
  //    v
  // a [5][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  // C supports three (and only three) forms of pointer arithmetic:
  //    - Adding an integer to a pointer
  //    - Subtracting an integer from a pointer
  //    - Subtracting one pointer from another
  //
  // our examples assume that the following dexlarations are in effect:
  //
  printf("These examples assume the following declarations:\n");
  printf("int a[10], *p, *q, i;\n\n");

  printf("Adding an integer to a pointer\n");
  p = &a[2];

  //       p [ ]
  //          v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  q = p + 3;

  //       p [ ]    q [ ]
  //          v        v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9

  p += 6;

  //                q [ ]    p [ ]
  //                   v        v
  // a [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
  //    0  1  2  3  4  5  6  7  8  9
}



void sec_12_2(void) {
  // Pointers and Arrays
  printf("\n\n");
  printf("12.2: Pointers for Array Processing\n----------------------------\n");
  
  // int *p = (int []){3, 0, 3, 4, 1};

  // The above is equivalent to:
  int a[] = {3, 0, 3, 4, 1};
  int *p = &a[0];

  // the pointer to a compound literal saves the explicit labeling of the
  // compound literal by assigning it to `a`
  printf("*p++ or *(p++) Value of exp is *p before increment, inc *p later \n");
  printf("(*p)++         Value of exp is *p before increment, inc *p later \n");
  printf("*++p or ++(*p) Inc p first, value of *p is after inc             \n");
  printf("++*p or ++(*p) Inc p first, value of *p is after inc             \n");
  
}


void sec_12_3(void) {
  // Using an Array Name as a Pointer
  printf("\n\n");
  printf("12.3: Array Name as a Pointer\n----------------------------------\n");
  
  // Given the following declaration:
  int a[10];

  // We can use the array name as a pointer to the first address:
  *a = 7; // Stores 7 in a[0]
  
  // We can modify a[1] through the pointer a+1
  *(a+1) = 12; // Stores 12 in a[1]

  printf("Idiom:\n");
  printf("\nfor (p = a; p < a + N; p++)\n\tsum += *p;\n\n");

  #define N 10

  int sum = 0;
  int *p;

  for (p = a; p < a + N; p++)
    sum += *p;

  printf("The array name is ALWAYS a pointer to the first element.\n");
  printf("You can change the value at its location with *a = x, but\n");
  printf("You can not change the **value** of a itself (as a pointer)\n");
  printf("So, a++ is INVALID\n\n");



}



int main(int argc, char *argv[]) {
  printf("Chapter 12: Pointers and Arrays\n----------------------------\n\n");

  sec_12_1();
  sec_12_2();
  sec_12_3();
  return EXIT_SUCCESS;
}

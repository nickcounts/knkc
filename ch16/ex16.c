/* Chapter 16, Exercise 16
 *
 * Which of the following statements about enumeration constants are true?
 *
 * a) An enumeration constant may represent any integer specified by the 
 *    programmer.
 *
 * b) Enumeration constants have exactly the same properties as constants 
 *    created using `#define`
 *
 * c) Enumeration constants have the values 0, 1, 2, ... by default
 *
 * d) All constants in an enumeration must have different values.
 *
 * e) Enumeration constants may be used as integers in expressions.
 *
 */

#include <stdio.h>


// A) C uses enum members as an int and it is guaranteed to function as an 
//    int. Technically negative numbers may be used.

// B) `#define` constants function as text replacement in the code, which 
//    means they do not interact with the type system the same way that 
//    enumeration constants do. Macros replace a value and then the 
//    compiler infers a type based on the text and how it's used.
//
//    Enums are guaranteed to be treated as ints. 
//

// D) Enumeration constants start at 0 and increment automatically unless the
//    programmer specifies a value. If a value is specified, the next 
//    enum constant will be incremented from the specified value.

// D) Enumeration members may share a numerical value.

// E) Enumeration constants may be used as integers in expressions. The C 
//    standard guarantees that enum constants can be used in `int` expressions


int main(void){
  enum test {
    ZERO,
    ONE,
    THREE = 3,
    FOUR,
    FOUR2 = 4,
    // HUH = 4.2, // ERROR: must have integer type
  };

  printf("Demonstrating automatic enum increments:\n");
  printf("   ZERO  has value : %d\n", ZERO);
  printf("   ONE   has value : %d\n", ONE);
  printf("   THREE has value : %d\n", THREE);
  printf("   FOUR  has value : %d\n", FOUR);
  printf("   FOUR2 has value : %d\n", FOUR2);

  printf("\nUsing enums in integer expressions: \n");
  printf("THREE * -FOUR : %d\n", THREE * - FOUR);

  return 0;
}

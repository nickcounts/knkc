/* Chapter 16, Exercise 2
 *
 * a) Declare structure variables named `c1`, `c2`, and `c3`, each having 
 *    members `real` and `imaginary` of type `double`
 *
 * b) Modify the declaration in part (a) so that `c1`'s members initially
 *    have the values `0.0` and `1.0` while `c2`'s members are `1.0` and 
 *    `0.0` initially. `c3` is not initialized
 *
 * c) Write statements that copy the members of `c2` into `c1`. Can this be 
 *    done in one statement?
 *
 * d) Write statements that add the corresponding members of `c1` and `c2`,
 *    storing the result in `c3`
 *
 */


// a) 
/*
struct real {
  double real;
  double imaginary;
} c1, c2, c3;
*/


// b) initialize with values
struct real {
  double real;
  double imaginary;
} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

#include <stdio.h>

void print_real(struct real r);

int main(void) {
  // c) copy c2 contents into c1 in one statement if possible

  c1 = c2; // This works as a single statement for structs

  printf("c1: ");
  print_real(c1);

  printf("\nc2: ");
  print_real(c2);

  printf("\n");

  // d) add the members of c1 and c2, store in c3
  c3.real = c1.real + c2.real;
  c3.imaginary = c1.imaginary + c2.imaginary;

  printf("\nc3: ");
  print_real(c3);

  printf("\n");

  return 0;
}


void print_real(struct real r) {
  printf("%f, ", r.real);
  printf("%f", r.imaginary);
}



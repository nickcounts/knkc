/* Chapter 16, Exercise 4
 *
 * a) Show how to declare a type named `complex` for a structure with two
 *    members `real` and `imaginary` of type `double`
 *
 * b) Use the `complex` type to declare variables named `c1` `c2` and `c3`
 *
 * c) Write a function named `make_complex` that stores its two arguments
 *    (both of type `double`) in a `complex` structure, then returns the 
 *    structure
 *
 * d) Write a function named `add_complex` that adds the corresponding
 *    members of its arguments, then returns the result as another 
 *    `complex` structure
 */

#include <stdio.h>

typedef struct {
  double real;
  double imaginary;
} complex;

complex c1, c2, c3;

complex make_complex(double r, double i);
complex add_complex(complex c1, complex c2);
void print_real(complex r);


int main(void) {

  // b) declare variables of type struct with `complex` tag
  complex c1, c2, c3;

  c1 = make_complex(1, 1);
  c2 = make_complex(2, 2);

  c3 = add_complex(c1, c2);

  printf("c1 : "); print_real(c1); printf("\n");
  printf("c2 : "); print_real(c2); printf("\n");
  printf("c3 : "); print_real(c3); printf("\n");


  return 0;
}


// d) write add_complex to do basic complex addition
complex add_complex(complex c1, complex c2){
  complex c = {.real=c1.real+c2.real, 
               .imaginary=c1.imaginary+c2.imaginary};
  return c;
}

// c) write `make_complex`
complex make_complex(double r, double i){
  complex c = {.real=r, .imaginary=i};
  return c;
}


void print_real(complex r) {
  printf("%f, ", r.real);
  printf("%f", r.imaginary);
}

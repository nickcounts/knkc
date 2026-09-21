/* Chapter 16, Exercise 7
 *
 * Assume that the fraction structure contains two members: `numerator` and 
 * `denominator` (both of type `int`). Write functions that perform the 
 * following operations on fractions:
 * 
 *
 * a) Reduce the fraction `f` to lowest terms. Hint: to reduce a fraction to 
 *    lowest terms, first compute the greatest common divisor (GSD) of the 
 *    numerator and denominator. Then, divide both the numerator and 
 *    denominator by the GCD
 *
 * b) Add the fractions f1 and f2
 *
 * c) Subtract the fraction f2 from the fraction f1
 *
 * d) Multiply the fractions f1 and f2
 *
 * e) Divide the fraction f1 by the fraction f2
 *
 * The fractions f, f1, and f2 will be arguments of type `struct fraction`
 * Each function will return a value of type `struct fraction`. The fractions 
 * returned by the functions in parts b through e should be reduced to lowest 
 * terms. Hint: you may use function (a) to help write the functions in parts
 * (b) through (e)
 */


#include <stdio.h>
#include "colors.h"

struct fraction {
  int numerator;
  int denominator;
};



void print_fraction(struct fraction f){
  printf("%d/", f.numerator);
  printf("%d",  f.denominator);
}

struct fraction make_fraction(int num, int denom){
  struct fraction f = {.numerator = num, .denominator = denom};
  return f;
}

// compute the greatest common divisor (GCD) of the numerator and denominator
int GCD(struct fraction f){
  int max_gcd;

  if (f.numerator >= f.denominator){
    max_gcd = f.denominator;
  } else {
    max_gcd = f.denominator;
  }

  for (int gcd = max_gcd; gcd > 0; gcd--){
    if (f.numerator % gcd == 0 && f.denominator % gcd == 0)
      return gcd;
  }

  return 1;
}


// Part A) Reduce fraction to lowest terms
struct fraction reduce_fraction(struct fraction f){
  int gcd = GCD(f);
  if (gcd == 1)
    return f;
  struct fraction fr = {
    .numerator = f.numerator / gcd,
    .denominator = f.denominator / gcd
  };
  return fr;
}


// Part B) Add fractions
struct fraction add_fractions(struct fraction f1, struct fraction f2){
  struct fraction f;
  int gcd, f1d, f2d;
  
  f1d = f1.denominator;
  f2d = f2.denominator;

  // Cross-multiply
  f1.numerator   *= f2d;
  f1.denominator *= f2d;
  f2.numerator   *= f1d;
  f2.denominator *= f1d;

  f.numerator   = f1.numerator + f2.numerator;
  f.denominator = f1.denominator; 

  gcd = GCD(f);

  // printf("DEBUG: add_fractions() :   f = "); print_fraction(f); printf("\n");
  // printf("DEBUG: add_fractions() : GCD = %d\n", gcd);

  return (struct fraction) {.numerator=f.numerator/gcd, 
                            .denominator=f.denominator/gcd};
}


// Part C) Subtract fraction f2 from f1
struct fraction subtract_fractions(struct fraction f1, struct fraction f2){
  struct fraction f;
  int gcd, f1d, f2d;
  
  f1d = f1.denominator;
  f2d = f2.denominator;

  // Cross-multiply
  f1.numerator   *= f2d;
  f1.denominator *= f2d;
  f2.numerator   *= f1d;
  f2.denominator *= f1d;

  f.numerator   = f1.numerator   - f2.numerator;
  f.denominator = f1.denominator;

  gcd = GCD(f);

  // printf("DEBUG: subtract_fractions() f = "); print_fraction(f); printf("\n");
  // printf("DEBUG: subtract_fractions() gcd = %d\n", gcd);  

  return (struct fraction) {.numerator=f.numerator/gcd, 
                            .denominator=f.denominator/gcd};
}


// Part D) Multiply fraction f1 and f2
struct fraction multiply_fractions(struct fraction f1, struct fraction f2){
  struct fraction f;

  f.numerator   = f1.numerator * f2.numerator;
  f.denominator = f1.denominator * f2.denominator;

  return reduce_fraction(f);
}


// Part E) Divide the fraction f1 by f2 
struct fraction divide_fractions(struct fraction f1, struct fraction f2){
  struct fraction f;
  f.numerator   = f1.numerator * f2.denominator;
  f.denominator = f1.denominator * f2.numerator;

  return reduce_fraction(f);
}


void print_header(char* part ,char* msg){
  printf("\n" MAGENTA "%-10s" CYAN "%s:\n", part, msg);
  printf(MAGENTA);
  printf("-----------------------------------------------------------\n");
  printf(RESET);
}


int main(void){
  struct fraction f, f1, f2;


  f = make_fraction(2, 6); // 2/6 is 1/3. GCD is 2?
  print_header("Part 0)", "GCD()");
  printf("GCD of   "); print_fraction(f); printf(" is: %d\n", GCD(f));


  // Part A) Test reduce fractions
  print_header("Part A)", "reduce_fraction()");
  printf("Reduced  "); print_fraction(f); printf(" is: "); 
  print_fraction(reduce_fraction(f)); printf("\n");


  // Part B) Test addition
  f1 = make_fraction(1, 3);
  f2 = make_fraction(2, 5);
  f  = add_fractions(f1, f2);

  print_header("Part B)", "add_fractions()");
  printf("1/3 + 2/5 is: "); print_fraction(f); printf("\n"); 


  // Part C) Test addition
  f1 = make_fraction(1, 2);
  f2 = make_fraction(1, 6);
  f  = subtract_fractions(f1, f2);

  print_header("Part C)", "subtract_fractions()");
  print_fraction(f1); printf(" - ");
  print_fraction(f2); printf(" is: "); 
  print_fraction(f); printf("\n"); 


  // Part D) Test multiplication
  f1 = make_fraction(1, 2);
  f2 = make_fraction(1, 6);
  f  = multiply_fractions(f1, f2);

  print_header("Part D)", "multiply_fractions()");
  print_fraction(f1); printf(" * ");
  print_fraction(f2); printf(" is: "); 
  print_fraction(f); printf("\n"); 


  // Part E) Test division
  f1 = make_fraction(1, 2);
  f2 = make_fraction(1, 6);
  f  = divide_fractions(f1, f2);

  print_header("Part E)", "divide_fractions()");
  print_fraction(f1); printf(" * ");
  print_fraction(f2); printf(" is: "); 
  print_fraction(f); printf("\n"); 




  return 0;
}


